#include <stdio.h>
#include <stdlib.h>

#define N 6
typedef struct position pos;
struct position {
    int row;
    int col;
};

int check_queen_pos(pos *p, int n, int row) {
    if (n == row)
        return 1;
    int col,
            safe = 1,
            queen;
    for (col = 0; col < n; col++) {
        for (queen = 0; queen < row; queen++) {
            safe = 1;
            if (p[queen].col == col || p[queen].row == row || p[queen].row - p[queen].col == row - col ||
                p[queen].row + p[queen].col == row + col) {
                safe = 0;
                break;
            }
        }
        if (safe) {
            p[row].col = col;
            p[row].row = row;
            if (check_queen_pos(p, n, row + 1))
                return 1;
        }
    }
    return 0;
}

int solve(pos *p, int n) {
    if (check_queen_pos(p, n, 0))
        return 1;
}

int main() {
    pos p[N];
    if (solve(p, N)) {
        for (int i = 0; i < N; i++) {
            printf("(%d %d)\n", p[i].row, p[i].col);
        }
    } else printf("no solve");
    return 0;
}