#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll mod = 1000000007;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(s.size()+2,vector<ll>(2));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][0]%=mod;
            dp[i+1][1]=dp[i][1]*3;
            dp[i+1][1]%=mod;
        }else{
            dp[i+1][0]=dp[i][0]*2;
            dp[i+1][0]%=mod;
            dp[i+1][1]=dp[i][0]+dp[i][1]*3;
            dp[i+1][1]%=mod;
        }
    }
    ll ans = (dp[n][0] + dp[n][1])%mod;
    cout << ans << endl;
    return 0;
}