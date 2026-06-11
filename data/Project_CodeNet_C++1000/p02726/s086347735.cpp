#include <bits/stdc++.h>
using namespace std;

const int N = 2004;

int n, x, y, ans[N];
bool vis[N];

void bfs(int start) {
    memset(vis, false, sizeof vis);

    vis[start] = vis[0] = vis[n + 1] = true;

    queue<pair<int, int>> qu;

    qu.push({start, 0});

    while (qu.empty() == false) {
        int u = qu.front().first, dis = qu.front().second;
        qu.pop();

        vector<int> adj = {u - 1, u + 1};

        if (u == x) {
            adj.push_back(y);
        } else if (u == y) {
            adj.push_back(x);
        }

        for (int v : adj) {
            if (vis[v] == false) {
                vis[v] = true;
                qu.push({v, dis + 1});
                ans[dis + 1]++;
            }
        }
    }
}

int main() {
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i] / 2 << endl;
    }

    return 0;
}

