#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    const ll MOD = 1e9+7;
    int n,m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(auto& si:s) cin >> si;
    for(auto& ti:t) cin >> ti;

    vector<vector<ll>> dp(n+1,vector<ll>(m+1, 0));
    rep(i,n+1) dp[i][0] = 1;
    rep(j,m+1) dp[0][j] = 1;

    rep(i,n) {
        rep(j,m) {
            dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1] - dp[i][j] + 3*MOD) % MOD;
            if(t[j] == s[i]) 
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}