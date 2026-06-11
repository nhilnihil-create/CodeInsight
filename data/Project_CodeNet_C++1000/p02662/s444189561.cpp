#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
const ll mod = 998244353;


int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
    dp[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, s+1) {
            dp[i+1][j] += 2 * dp[i][j];
            dp[i+1][j] %= mod;
            if(j + a[i] <= s){
                dp[i+1][j+a[i]] += dp[i][j];
                dp[i+1][j+a[i]] %= mod;
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}