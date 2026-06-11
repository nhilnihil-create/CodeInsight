#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> comps, visited(n);
    int siz = 0;
    function<void(int)> dfs = [&](int u) {
        visited[u] = 1;
        siz++;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            siz = 0;
            dfs(i);
            comps.push_back(siz);
        }
    }
    int ans = 0;
    for (int x : comps)
        ans = max(ans, x);
    cout << ans << '\n';
}