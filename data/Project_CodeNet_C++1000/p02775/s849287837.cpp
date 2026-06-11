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
    string s;
    cin >> s;
    ll n = len(s);
    // dp[figre][0:just, 1:over]
    vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i, n) {
        ll cv = s[i] - '0';
        chmin(dp[i + 1][0], dp[i][0] + cv);
        chmin(dp[i + 1][0], dp[i][1] + (10 - cv));
        chmin(dp[i + 1][1], dp[i][0] + (cv + 1));
        chmin(dp[i + 1][1], dp[i][1] + (10 - cv - 1));
    }
    ll ans = min(dp[n][0], dp[n][1] + 1);
    cout << ans << endl;
    return 0;
}
