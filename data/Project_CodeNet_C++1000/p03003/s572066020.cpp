//PDF解説に倣ってDP
#include<bits/stdc++.h>
using namespace std;

int main(){
  int M=1e9+7,n,m;
  cin>> n >> m;
  vector<int> s(n),t(m);
  for (int i=0; i<n; i++) cin>> s[i];
  for (int i=0; i<m; i++) cin>> t[i];
  
  vector<vector<int>> dp(n,vector<int>(m));
  if (s[0]==t[0]) dp[0][0]=1;
  for (int i=1; i<n; i++){
    dp[i][0]=dp[i-1][0];
    if (s[i]==t[0]) dp[i][0]++;
  }
  for (int i=1; i<m; i++){
    dp[0][i]=dp[0][i-1];
    if (s[0]==t[i]) dp[0][i]++;
  }
  for (int i=1; i<n; i++){
    for (int j=1; j<m; j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
      if (s[i]==t[j]) dp[i][j]+=1;
      else dp[i][j]-=dp[i-1][j-1];
      dp[i][j]%=M;
      if (dp[i][j]<0) dp[i][j]+=M; //ひょっとして負になってる？
    }
  }
  cout<< (dp[n-1][m-1]+1)%M <<endl;
}