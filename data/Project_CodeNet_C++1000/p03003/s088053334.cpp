#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    ll n, m;
    cin >> n >> m;
    vector<ll> s(n), t(m);
    for(auto &e: s) cin >> e;
    for(auto &e: t) cin >> e;

    vector<vector<ll>> dp(m+1, vector<ll>(n+1));

    for(ll i=0; i<=n; i++)
        dp[0][i] = 1;

    for(ll i=1; i<=m; i++) {
        dp[i][0] = 1;
        for(ll j=1; j<=n; j++) {
            dp[i][j] = (MOD + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0)) % MOD;
        }
    }
    cout << dp[m][n] << endl;
}
