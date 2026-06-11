#include <bits/stdc++.h>
using namespace std;
 


int main() {
  string S;cin>>S;
  long MOD=1000000007;
  vector<vector<long>> dp(S.length(),vector<long>(13,0));
  //dp[i][j]=:i+1桁目までで13で割った余りがjの数
  for(int i=0;i<13;i++)dp[0][i]=0;
  if(S[0]=='?'){
    for(int i=0;i<=9;i++)dp[0][i]=1;
  }else{
    dp[0][S[0]-'0']=1;
  }
  for(int i=1;i<S.length();i++){
    int n=S[i]-'0';
    if(S[i]=='?'){
      for(int j=0;j<13;j++){
        for(int n=0;n<=9;n++){
          dp[i][(j*10+n)%13]=(dp[i][(j*10+n)%13]+dp[i-1][j])%MOD;
      	}
      }
    }else{
      for(int j=0;j<13;j++){
        dp[i][(j*10+n)%13]=(dp[i][(j*10+n)%13]+dp[i-1][j])%MOD;
      }
    }
  }
  cout<<dp[S.length()-1][5]<<endl;
}
