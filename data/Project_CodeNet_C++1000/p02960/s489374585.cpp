#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;

signed main() {
  string S;
  cin >> S;
  
  //前からi文字の時点で、13で割った余りがjであるものの個数
  vector<vector<int>> dp((int)S.size(), vector<int>(13));
  if( S.at(0) == '?' ){
    for( int j = 0; j < 10; j++ ) dp[0][j] = 1;
  }else{
    dp[0][S.at(0)-'0'] = 1;
  }
 
  for( int i = 1; i < S.size(); i++ ){
    if( S.at(i) == '?' ){
      for( int num = 0; num < 10; num++ ){
        for( int j = 0; j < 13; j++ ){ //前のあまり
          dp[i][(j*10+num)%13] += dp[i-1][j];
          dp[i][(j*10+num)%13] %= MOD;
        }
      }
    }else{
      for( int j = 0; j < 13; j++ ){
        int num = S.at(i)-'0';
        dp[i][(j*10+num)%13] += dp[i-1][j];
        dp[i][(j*10+num)%13] %= MOD;
      }
    }
  }
  cout << dp[S.size()-1][5] << endl;
  
}
