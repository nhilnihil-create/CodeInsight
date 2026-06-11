#include<bits/stdc++.h>
using namespace std;
int main() {
  int h,m,i,j;
  cin>>h>>m;
  vector<int> x(m),y(m)/*,dp(m)*/;
  vector<vector<int>> dp(m+1,vector<int>(h+1,1e8));
  for(i=0;i<=m;i++) dp[i][0]=0;
  for(i=0;i<m;i++) cin>>x[i]>>y[i];
  for(i=0;i<m;i++){
    for(j=1;j<=h;j++){
      dp[i+1][j]=min(min(dp[i][j],dp[i][max(0,j-x[i])]+y[i]),dp[i+1][max(0,j-x[i])]+y[i]);
    }
  }
/*  for(i=0;i<=m;i++){
    for(j=0;j<=h;j++) cout<<dp[i][j]<<' ';
    cout<<endl;
  }*/
  cout<<dp[m][h]<<endl;
}