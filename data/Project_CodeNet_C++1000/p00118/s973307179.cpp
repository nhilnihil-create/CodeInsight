//
// Created by yijiezhu on 12/20/16.
//

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 101

int m, n;
char matrix[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cnt;

void dfs(int i, int j, char ch) {
    visited[i][j] = true;
    matrix[i][j] = (char) ('a' + cnt - 1);
    int delta[] = {0, 1, 0, -1, 0};
    for (int q = 0; q < 4; q++) {
        int ni = i + delta[q], nj = j + delta[q+1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        if (visited[ni][nj] || matrix[ni][nj] != ch) continue;
        dfs(ni, nj, ch);
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++;
                dfs(i, j, matrix[i][j]);
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    while (true) {
        cin >> m >> n;
        if (m == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        cnt = 0;
        memset(visited, false, sizeof(visited));
        solve();
    }
}