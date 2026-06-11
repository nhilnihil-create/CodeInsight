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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    string s;
    cin >> s;
    reverse(all(s));
    ll n = len(s);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 2) {
            ll x = s[i] - '0';
            x += j;
            if (x < 10) dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + x);
            if (x > 0) dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + (10 - x));
        }
    }
    cout << min(dp[n][0], dp[n][1] + 1) << endl;
    return 0;
}
