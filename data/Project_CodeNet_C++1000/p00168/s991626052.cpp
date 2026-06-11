#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int dp[31][4] = {};
  dp[1][1] = 1;
  dp[2][1] = dp[2][2] = 1;
  dp[3][1] = 2;
  dp[3][2] = dp[3][3] = 1;
  for(int i=4;i<31;++i){
    for(int j=1;j<4;++j){
      dp[i][j] += dp[i-j][1] + dp[i-j][2] + dp[i-j][3]; 
    }
  }
  while(cin>>n, n){
    int ans=0;
    for(int i=1;i<4;++i)
      ans += dp[n][i];
    ans = (ans+9)/10;
    ans = (ans+364)/365;
    cout<<ans<<endl;
  }
  return 0;
}