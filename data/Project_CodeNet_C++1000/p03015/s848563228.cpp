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
    const ll mod = 1e9 + 7;
    string s;
    cin >> s;
    ll n = len(s);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[0][0] = 1;
    rep(i, n) {
        if (s[i] == '1') {
            dp[i + 1][0] = (dp[i][0] * 2) % mod;
            dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % mod;
        }
        else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (dp[i][1] * 3) % mod;
        }
    }
    cout << ((dp[n][0] + dp[n][1]) % mod) << endl;
    return 0;
}
