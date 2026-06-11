#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int h[n+1]={};
    for(int i=1;i<=n;i++)cin>>h[i];
    vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(x+1,vector<long long>(n+1,1000000000000000)));
    //i列見て、j行捨てて、末尾がk列目のとき最小コスト
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            for(int k=0;k<=n;k++){
                dp[i+1][j][i+1]=min(dp[i+1][j][i+1],dp[i][j][k]+max(0,h[i+1]-h[k]));
                if(j<x)dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]);
            }
        }
    }
    long long ans=1000000000000000;
    for(int i=0;i<=n;i++)ans=min(ans,dp[n][x][i]);
    cout<<ans<<endl;
    return 0;
}