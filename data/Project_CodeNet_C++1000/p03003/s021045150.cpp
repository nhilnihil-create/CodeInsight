//PDF解説に倣ってDP
#include<bits/stdc++.h>
using namespace std;

int main(){
  int M=1e9+7,n,m;
  cin>> n >> m;
  vector<int> s(n),t(m);
  for (int i=0; i<n; i++) cin>> s[i];
  for (int i=0; i<m; i++) cin>> t[i];
  
  vector<vector<int>> dp(n+1,vector<int>(m+1));
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j];
      if (s[i]==t[j]) dp[i+1][j+1]++;
      else dp[i+1][j+1]-=dp[i][j];
      dp[i+1][j+1]%=M;
      if (dp[i+1][j+1]<0) dp[i+1][j+1]+=M;
    }
  }
  cout<< (dp[n][m]+1)%M <<endl;
}
//ついでに簡略化