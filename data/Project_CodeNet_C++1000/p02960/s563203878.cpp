#include <bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;

int main(){
  string S;
  cin >> S;
  long long dp[100010][13]={};
  long long d=1;
  dp[S.size()][0]=1;
  for(int i=1; i<13; i++) dp[S.size()][i]=0;
  for(int i=S.size()-1; i>=0; i--){
    if(S[i]=='?'){
      for(int j=0; j<13; j++){
        for(int m=0; m<10; m++){
          dp[i][(j+m*d)%13]+=dp[i+1][j];
          dp[i][(j+m*d)%13]%=MOD;
        }
      }
    }else{
      long long a=S[i]-'0';
      for(int j=0; j<13; j++){
        dp[i][(j+a*d)%13]=dp[i+1][j];
      }
    }
    d=d*10%13;
  }
  cout << dp[0][5] << endl;
}