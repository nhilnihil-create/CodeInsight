#include<bits/stdc++.h>
using namespace std;
int main(){
    const int inf=1000000000;
    int n,m;
    cin>>n>>m;
    int N=1<<n;
    vector<vector<int>>dp(m+1,vector<int>(N,inf));
    dp[0][0]=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int c[b];
        for(int j=0;j<b;j++){
            cin>>c[j];
            c[j]--;
        }
        for(int j=0;j<N;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            int newj=j;
            for(int k=0;k<b;k++)newj|=(1<<c[k]);
            dp[i+1][newj]=min(dp[i+1][newj],dp[i][j]+a);
        }
    }
    if(dp[m][N-1]==inf)cout<<"-1"<<endl;
    else cout<<dp[m][N-1]<<endl;
    return 0;
}