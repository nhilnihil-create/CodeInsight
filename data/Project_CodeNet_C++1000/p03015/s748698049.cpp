#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    rep(i, n) {
        if ( s[i] == '0' ) {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1]; 
        }
        else {
            dp[i+1][1] = ( dp[i][0] + dp[i][1] ) % mod;
        }

        if ( s[i] == '0') {
            dp[i+1][1] = ( dp[i+1][1] + dp[i][1] * 2 % mod ) % mod;
        }
        else {
            dp[i+1][0] = ( dp[i+1][0] + dp[i][0] * 2 % mod ) % mod;
            dp[i+1][1] = ( dp[i+1][1] + dp[i][1] * 2 % mod ) % mod;
        }
    }
    ll ans = ( dp[n][0] + dp[n][1] ) % mod;
    cout << ans << endl;
    return 0;
}
