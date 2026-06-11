#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int v, int p, const vector<vector<int>> &G, vector<ll> &sum) {
    for (auto nv : G[v]) {
        if (nv == p) continue;
        sum[nv] += sum[v];
        dfs(nv, v, G, sum);
    }
}

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> G(n);
    vector<ll> sum(n,0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < q; i++) {
        int p; ll x; cin >> p >> x; p--;
        sum[p] += x;
    }

    dfs(0, -1, G, sum);

    for (int i = 0; i < n; i++) cout << sum[i] << (i == n - 1 ? "\n" : " ");
    return 0;
}