#include "bits/stdc++.h"
using namespace std;

const int maxn = 105;
string s[maxn];
int dp[maxn][maxn];

int main(int argc, char const *argv[])
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }
  memset(dp, 63, sizeof dp);
  dp[0][0] = 0;
  if(s[0][0] == '#'){
    dp[0][0] = 1;
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s[i][j] == '.'){
        if(i + 1 < n){
          if(s[i + 1][j] == '.'){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
          }else {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
          }
        }
        if(j + 1 < m){
          if(s[i][j + 1] == '.'){
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
          }else {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
          }
        }
      }else {
        if(i + 1 < n){
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }if(j + 1 < m) {
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
      }
    }
  }
  cout << dp[n - 1][m - 1] << endl;

  return 0;
}