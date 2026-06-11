/**
 *    author:  FromDihPout
 *    created: 2020-09-17
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> val;

void dfs(int u, int par, int x) {
    val[u] += x;
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u, val[u]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    val.resize(n);
    for (int i = 0; i < q; i++) {
        int node, x;
        cin >> node >> x;
        val[node - 1] += x;
    }
    
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << val[i] << ' ';
    }
    cout << '\n';
    return 0;
}