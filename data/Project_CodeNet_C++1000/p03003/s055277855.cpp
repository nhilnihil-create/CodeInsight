#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,1));
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll j=0; j<m; j++) cin>>b[j];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            dp[i+1][j+1]=dp[i+1][j] + dp[i][j+1] - dp[i][j];
            if(a[i]==b[j]) dp[i+1][j+1]+=dp[i][j];
            dp[i+1][j+1] += mod;
            dp[i+1][j+1] %= mod;
        }
    }
    cout<<dp[n][m]<<endl;
    
    // for(ll i=0; i<=n; i++){
    //     for(ll j=0; j<=m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}