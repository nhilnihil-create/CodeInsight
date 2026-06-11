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
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(1 << n, inf);
    dp[0] = 0;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        vector<ll> c(b);
        rep(j, b) cin >> c[j];
        rep(bit, 1 << n) {
            if (dp[bit] == inf) continue;
            ll nb = bit;
            rep(j, b) nb |= 1 << (c[j] - 1);
            chmin(dp[nb], dp[bit] + a);
        }
    }
    cout << ((dp[(1 << n) - 1] == inf) ? -1 : dp[(1 << n) - 1]) << endl;
    return 0;
}
