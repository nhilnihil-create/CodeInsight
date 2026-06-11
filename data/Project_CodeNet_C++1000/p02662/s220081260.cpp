#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=998244353;
    int n,s;
    cin>>n>>s;
    int a[n];
    vector<vector<long long>>dp(n+1,vector<long long>(s+1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<=s;j++){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*2)%mod;
            if(j+a[i]<=s)dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
        }
    }
    cout<<dp[n][s]<<endl;
    return 0;
}