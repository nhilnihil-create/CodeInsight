#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
#define all(c) begin(c), end(c)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m;
    vector<int> adj[100100];
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    cin >> s >> t;
    s--, t--;

    vvl dist(100100, vl(3, 1e18));
    dist[s][0] = 0;
    queue<pll> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int node = p.first;
        int kind = p.second;
        if (node == t && kind == 0) {
            cout << int(dist[t][0] / 3) << endl;
            return 0;
        }
        for (int to : adj[node]) {
            int next_kind = (kind + 1) % 3;
            if (dist[to][next_kind] == 1e18) {
                dist[to][next_kind] = dist[node][kind] + 1;
                q.emplace(to, next_kind);
            }
        }
    }
    puts("-1");
}
