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

ll n, q;
vector<vector<ll>> g;
vector<ll> dp;

void dfs(ll v, ll p = -1) {
    if (p != -1) dp[v] += dp[p];
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n >> q;
    g.resize(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.resize(n, 0);
    rep(i, q) {
        ll p, x;
        cin >> p >> x;
        p--;
        dp[p] += x;
    }
    dfs(0);
    rep(i, n) printf("%lld%s", dp[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
