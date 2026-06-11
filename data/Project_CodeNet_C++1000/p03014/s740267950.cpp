#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char maze[n+1][m+1];
    int col[n+1][m+1], row[n+1][m+1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '#') continue;
            int start = j, end = j;
            for (int k = j + 1; k < m && maze[i][k] == '.'; k++) {
                end = k;
            }
            for (int k = start; k <= end; k++) {
                row[i][k] = (end - start + 1);
            }
            j = end;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[j][i] == '#') {
                continue;
            }
            int start = j, end = j;
            for (int k = j + 1; k < n && maze[k][i] == '.'; k++) {
                end = k;
            }
            for (int k = start; k <= end; k++) {
                col[k][i] = (end - start + 1);
            }
            j = end;
        }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                ans = max(ans, row[i][j] + col[i][j] - 1);
            }
        }
    }
    cout << ans << endl;
}