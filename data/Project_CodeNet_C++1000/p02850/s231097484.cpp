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

    int n;
    cin >> n;
    vt<vt<pii>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vt<int> colors(n);
    function<void(int, int, int)> dfs = [&](int u, int p, int c) {
        int numC = 1;
        for (pii &v : adj[u]) {
            if (v.fi == p) continue;

            if (numC == c) numC++;
            colors[v.se] = numC;
            dfs(v.fi, u, numC);
            numC++;
        }
    };
    dfs(0, -1, -1);

    int mxEdges = 1;
    for (int i = 0; i < n; i++) {
        mxEdges = max(mxEdges, sz(adj[i]));
    }
    cout << mxEdges << '\n';

    for (int i = 1; i < n; i++) {
        cout << colors[i] << '\n';
    }
}
