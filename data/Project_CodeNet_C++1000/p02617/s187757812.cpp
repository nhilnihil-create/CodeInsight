#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0, sum = 0;
    for(int r = 0; r < n; r++) {
        sum += 1;
        vector<int> adj;
        for(auto v: g[r]) {
            if(v < r) {
                adj.push_back(v);
            }
        }
        sort(adj.begin(), adj.end());
        sum += r;
        if(adj.size()) {
            for(int i = 0; i < adj.size(); i++) {
                sum -= 1ll * (adj.size() - i) * (i ? adj[i] - adj[i - 1]: adj[i] + 1);
            }
        }
        //cerr << r << ' ' << sum << '\n';
        ans += sum;
    }
    cout << ans << '\n';
    return 0;
}
