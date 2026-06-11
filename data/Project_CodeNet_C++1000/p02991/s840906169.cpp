#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    ll s, t;
    cin >> s >> t;
    s--; t--;
    vector<vector<ll>> dp(n, vector<ll>(3, inf));
    queue<pair<ll, ll>> q;
    q.push(make_pair(s, 0));
    dp[s][0] = 0;
    while(!q.empty()) {
        pair<ll, ll> p = q.front(); q.pop();
        ll u = p.first;
        ll step = p.second;
        for(auto v : g[u]) {
            ll ns = (step + 1) % 3;
            ll nv = dp[u][step] + ((step == 0) ? 1 : 0);
            if (dp[v][ns] <= nv) continue;
            dp[v][ns] = nv;
            q.push(make_pair(v, ns));
        }
    }
    if (dp[t][0] == inf) {
        cout << -1 << endl;
    }
    else {
        cout << dp[t][0] << endl;
    }
    return 0;
}
