#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int dp[100005][13];
int main(){
  string S;
  cin >> S;
  if(S[0]!='?')dp[0][(S[0]-'0')]++;
  else for(int k=0;k<10;k++)dp[0][k]++;
  for(int i=1;i<S.length();i++){
    for(int j=0;j<13;j++){
      if(S[i]!='?'){
        dp[i][((j*10)%13+(S[i]-'0')%13)%13]+=dp[i-1][j];
        dp[i][((j*10)%13+(S[i]-'0')%13)%13]%=mod;
      }
      else{
        for(int k=0;k<10;k++){
          dp[i][((j*10)%13+k%13)%13]+=dp[i-1][j];
          dp[i][((j*10)%13+k%13)%13]%=mod;
        }
      }
    }
  }
  cout << dp[S.length()-1][5] << endl;
}