#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;
    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vt<int> ans(n), add(n);
    while (q--) {
        int p, x;
        cin >> p >> x;
        add[--p] += x;
    }

    function<void(int, int, int)> dfs = [&](int u, int p, int b) {
        b += add[u];
        ans[u] = b;
        for (int v : adj[u]) {
            if (v == p) continue;

            dfs(v, u, b);
        }
    };
    dfs(0, -1, 0);

    for (int i : ans) cout << i << ' ';
}
