#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int n=S.size();
  long mod=1e9+7;
  vector<vector<long>> dp(n+1,vector<long>(13));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<13;j++){
      if(S[i]=='?'){
        for(int k=0;k<=9;k++) dp[i+1][(j*10+k)%13]+=dp[i][j],dp[i+1][(j*10+k)%13]%=mod;
      }
      else{
        long k=S[i]-'0';
        dp[i+1][(j*10+k)%13]+=dp[i][j];
        dp[i+1][(j*10+k)%13]%=mod;
      }
    }
  }
  cout<<dp[n][5]<<endl;
}
