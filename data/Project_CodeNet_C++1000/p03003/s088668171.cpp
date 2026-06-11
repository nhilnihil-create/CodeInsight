#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define mod (int)(1e9 + 7) 
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll arr1[n],arr2[m];
    for(ll i=0;i<n;i++)
    cin>>arr1[i];
    for(ll j=0;j<m;j++)
    cin>>arr2[j];
    ll dp[n + 1][m + 1]; 
    for (ll i = 0; i <= n; i++) 
        dp[i][0] = 1; 
    for (ll j = 0; j <= m; j++) 
        dp[0][j] = 1; 
  
    for (ll i = 1; i <= n; ++i) { 
        for (ll j = 1; j <= m; ++j) { 
            dp[i][j] = dp[i - 1][j] 
                       + dp[i][j - 1] 
                       - dp[i - 1][j - 1]; 
            if (arr1[i - 1] == arr2[j - 1]) 
                dp[i][j] += dp[i - 1][j - 1]; 
  
            dp[i][j] += mod; 
            dp[i][j] %= mod; 
        } 
    } 
    cout<<dp[n][m];
    return 0;
} 
