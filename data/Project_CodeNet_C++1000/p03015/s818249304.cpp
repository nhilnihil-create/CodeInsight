#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
  string s;cin >> s;
  int n=s.size();
  ll dp[n+1][2];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
      int p=s[i]-'0';
      if(p){
          dp[i+1][0]+=dp[i][0]*2;
          dp[i+1][1]+=dp[i][1]*3+dp[i][0];
      }
      else{
          dp[i+1][0]+=dp[i][0];
          dp[i+1][1]+=dp[i][1]*3;
      }
      dp[i+1][0]%=mod;
      dp[i+1][1]%=mod;
  }
  cout << (dp[n][0]+dp[n][1])%mod << endl;
}