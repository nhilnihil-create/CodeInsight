#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n,m;
    cin>>n>>m;
    int s[n],t[m];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++)cin>>t[i];
    vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j])dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]+1)%mod;
            else dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]-dp[i][j]+mod)%mod;
        }
    }
    cout<<(dp[n][m]+1)%mod<<endl;
    return 0;
}