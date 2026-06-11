#include <iostream>

using namespace std;
bool board[7][7];
bool row[7], col[7];
int h, w, k, tol = 0;

void dfs(int i, int j) {
    if (i < h) {
        col[i] = true;
        dfs(i + 1, j);
        col[i] = false;
        dfs(i + 1, j);
    } else if (j < w) {
        row[j] = true;
        dfs(i, j + 1);
        row[j] = false;
        dfs(i, j + 1);
    }
    if (i == h && j == w) {
        int sum = 0;
        for (int i1 = 0; i1 < h; i1++)
            for (int j1 = 0; j1 < w; j1++)
                sum += !col[i1] && !row[j1] && board[i1][j1];
        tol += sum == k;
    }
}

int main() {
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            board[i][j] = c == '#';
        }
    dfs(0, 0);
    cout << tol;
    return 0;
}