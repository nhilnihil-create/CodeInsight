#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    while (cin >> m >> n, n || m) {
        vector<vector<int>> v(n, vector<int>(m));
        for (auto& i : v) for (auto& j : i) cin >> j;

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) continue;
                count++;
                queue<pair<int,int>> que;
                que.push(make_pair(i, j));

                while (que.size()) {
                    auto p = que.front();
                    que.pop();
                    int x = p.first;
                    int y = p.second;

                    if (v[x][y] == 0) continue;

                    v[x][y] = 0;

                    for (int k = 0; k < 8; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] == 1) {
                            que.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}

