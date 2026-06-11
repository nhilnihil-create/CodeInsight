#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll n,m;
ll dp[6500][6500]={0};
void solve(ll *s, ll *t){
    memset(dp, 0,sizeof dp);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = (1 + dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            else
            dp[i][j] = ((dp[i-1][j]%mod + dp[i][j-1])%mod - dp[i-1][j-1]%mod + mod) %mod;
        }
    }
    // return dp[n][m];
}
int main() {
    cin>>n>>m;
    ll s[n],t[m];
    for(ll i=0;i<n;i++)cin>>s[i];
    for(ll i=0;i<m;i++)cin>>t[i];
    solve(s,t);
    cout<< (dp[n][m] + 1) %mod;
    return 0;
}