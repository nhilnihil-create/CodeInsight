#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    ll n,m,mod=1e9+7; cin>>n>>m;
    vector<ll> s(n),t(m);
    ll dp[2005][2005];
    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            (dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%=mod;
            if(s[i-1]==t[j-1]) (dp[i][j] += dp[i-1][j-1] + 1)%=mod;
        }
    }

    cout << (dp[n][m] + 1) % mod << endl;
}