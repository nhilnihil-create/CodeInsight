//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;

const int MAXN = 1003;
int n;
vector<int> adjList[MAXN * MAXN];
int grid[MAXN][MAXN];
int idx[MAXN][MAXN];
int vis[MAXN * MAXN];
int res;
int ans[MAXN * MAXN];
bool f = false;

void dfs(int u) {
    vis[u] = 1;
    ans[u] = 0;
    for (int v : adjList[u]) {
        if (vis[v] == 1) {
            f = true;
            return;
        } else if (vis[v] == 0) {
            dfs(v);
            if (f)
                return;
        }
        ans[u] = max(ans[u], ans[v] + 1);
    }
    res = max(res, ans[u]);
    vis[u] = 2;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    cin >> n;
    int id = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> grid[i][j];
            int u = min(i, grid[i][j]);
            if (idx[u][i + grid[i][j] - u] == 0) idx[u][i + grid[i][j] - u] = id++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - 2; ++j) {
            int u = min(i, grid[i][j]);
            int v = min(i, grid[i][j + 1]);
            adjList[idx[u][i + grid[i][j] - u]].push_back(idx[v][i + grid[i][j + 1] - v]);
        }
    }

    for (int i = 1; i < id; ++i) {
        if (vis[i] == 0)
            dfs(i);
        if (f) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << res + 1 << '\n';

    return 0;
}