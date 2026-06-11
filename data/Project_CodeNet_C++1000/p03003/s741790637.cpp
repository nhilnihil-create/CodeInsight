#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,s[2009],t[2009],dp[2009][2009];
signed main(){
    cin>>n>>m;
    for(int i=0;i++<n;)cin>>s[i];
    for(int i=0;i++<m;)cin>>t[i];
    for(int i=0;i++<n;)for(int j=0;j++<m;){
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        if(s[i]==t[j])dp[i][j]+=dp[i-1][j-1]+1;
        (dp[i][j]+=mod)%=mod;
    }
    cout<<(dp[n][m]+1)%mod<<endl;
}