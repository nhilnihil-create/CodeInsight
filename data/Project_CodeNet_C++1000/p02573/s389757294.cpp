#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dfs(int x, vector<vector<int>> &g, vector<int> &vis) {
    int c = 1;
    for (int i : g[x]) {
        if (!vis[i]) {
            vis[i] = 1;
            c += dfs(i, g, vis);
        }
    }
    return c;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1);
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            r = max(r, dfs(i, g, vis));
        }
    }
    cout << r << endl;
    return 0;
}
