#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q, a, b, p, x;
vector<ll> g[200005];
vector<ll> arr(200005, 0), ans(200005, 0);

void dfs(ll node, ll parent, ll val) {
    ans[node] = val;
    for (auto adj : g[node]) {
        if (adj != parent) {
            dfs(adj, node, val + arr[adj]);
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < q; i++) {
        cin >> p >> x;
        arr[p] += x;
    }

    dfs(1, -1, arr[1]);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}