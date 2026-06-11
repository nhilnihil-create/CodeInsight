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
    const ll inf = LONG_LONG_MIN / 2 + 1;
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<ll>> dp(t + 1, vector<ll>(2, inf));
    dp[0][0] = 0;
    rep(i, n) {
        rrep(j, t) {
            ll nt = j + a[i];
            if (nt <= t) {
                chmax(dp[nt][0], dp[j][0] + b[i]);
                chmax(dp[nt][1], dp[j][1] + b[i]);
            }
            chmax(dp[j + 1][1], dp[j][0] + b[i]);
        }
    }
    ll ans = 0;
    rep(i, t + 1) rep(j, 2) chmax(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}
