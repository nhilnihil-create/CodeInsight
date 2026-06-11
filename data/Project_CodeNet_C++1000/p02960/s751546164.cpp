#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main(){
  string s;
  cin>>s;
  int mod=1000000007;
  vector<vector<int>>dp(s.size()+1,vector<int>(13));//i文字までにあまりjの数がいくつあるか
  
  if(s.at(0)=='?'){
    rep(i,10){
      dp[1][i]=1;
    }
  }
  else{
    dp[1][s.at(0)-'0']=1;
  }
  
  rep2(i,2,s.size()+1){
    rep(j,13){
      if(s.at(i-1)=='?'){
        rep(k,10){
          dp[i][(j*10+k)%13]+=dp[i-1][j];
          dp[i][(j*10+k)%13]%=mod;
        }
      }
      else{
        dp[i][(j*10+s.at(i-1)-'0')%13]=dp[i-1][j];
      }
    }
  }
  
  cout<<dp[s.size()][5]<<endl;
}