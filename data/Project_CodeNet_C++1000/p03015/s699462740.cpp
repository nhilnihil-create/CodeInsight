#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string l;
    cin >> l;
    ll n = l.size();
    const ll MOD = 1e9+7;
    ll dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 2;
    for(i = 1;i < n;++i){
        if(l.at(i) == '1'){
            dp[i][0] = 3*dp[i-1][0] + dp[i-1][1];
            dp[i][1] = 2*dp[i-1][1];
        }else{
            dp[i][0] = 3*dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }
        rep(j,3){
            dp[i][j] %= MOD;
        }
    }
    ll ans = dp[n-1][0] + dp[n-1][1];
    cout << ans%MOD << endl;
    return 0;
}