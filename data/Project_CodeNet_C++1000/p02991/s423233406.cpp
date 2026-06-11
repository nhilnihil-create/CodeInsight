#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

ll n, m;
vector<vector<ll>> g;
vector<vector<ll>> dist;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    ll s, t;
    cin >> s >> t;
    s--; t--;
    dist.resize(n, vector<ll>(3, inf));
    queue<pair<ll, ll>> q;
    q.push(make_pair(s, 0));
    dist[s][0] = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        ll u = p.first, d = p.second;
        for(auto v : g[u]) {
            ll par = (d + 1) % 3;
            if (dist[v][par] <= (d + 1)) continue;
            dist[v][par] = d + 1;
            q.push(make_pair(v, d + 1));
        }
    }
    if (dist[t][0] == inf) cout << -1 << endl;
    else cout << (dist[t][0] / 3) << endl;
    return 0;
}
