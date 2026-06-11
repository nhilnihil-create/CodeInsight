#include<bits/stdc++.h>
using namespace std;
int main() {
  int h,m,i,j;
  cin>>h>>m;
  vector<int> x(m),y(m),dp(h+1,1e8);
  dp[0]=0;
  for(i=0;i<m;i++) cin>>x[i]>>y[i];
  for(i=0;i<m;i++){
    for(j=1;j<=h;j++){
      dp[j]=min(dp[j],dp[max(0,j-x[i])]+y[i]);
    }
  }
//  for(j=0;j<=h;j++) cout<<dp[j]<<' ';
  cout<<dp[h]<<endl;
}