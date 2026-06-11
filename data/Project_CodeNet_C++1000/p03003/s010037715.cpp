#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

ll dp[2222][2222];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll mod = 1e9+7;
    ll n,m;
    cin>>n>>m;
    int s[n],t[m];
    for(int i=0;i<n;i++) cin>>s[i];
    for(int j=0;j<m;j++) cin>>t[j];
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int i=0;i<=m;i++) dp[0][i] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1] += dp[i+1][j] + dp[i][j+1] + mod - dp[i][j]; 
            if(s[i] == t[j]){
                dp[i+1][j+1] += dp[i][j];
            }
            dp[i+1][j+1] %= mod;
            //cerr << i << " " << j << " " << dp[i+1][j+1] << endl;
        }
    }
    cout << dp[n][m] << endl;

}