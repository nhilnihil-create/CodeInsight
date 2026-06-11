#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[3009],dp[3009][3009],xar[3009],i,j,mod=998244353,zx,xc,pas;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    for(i=1; i<=a; i++) cin>>f[i];
    xar[0]=1;
    for(i=1; i<=3002; i++){
        xar[i]=xar[i-1]*2;
        xar[i]%=mod;
    }
    for(i=1; i<=a; i++){
        for(j=1; j<f[i]; j++){
            dp[i][j]=dp[i-1][j]*2;
            dp[i][j]%=mod;
        }
        j=f[i];
        dp[i][j]=dp[i-1][j]*2+xar[i-1];
        dp[i][j]%=mod;
        for(j=f[i]+1; j<=b; j++){
            dp[i][j]=dp[i-1][j]*2+dp[i-1][j-f[i]];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[a][b];
    return 0;
}