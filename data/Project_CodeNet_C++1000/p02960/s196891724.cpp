#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<long long>> dp(N + 1, vector<long long>(13, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++){
    if (S[i] != '?'){
      for (int j = 0; j < 13; j++){
        dp[i + 1][(j * 10 + S[i] - '0') % 13] += dp[i][j];
        dp[i + 1][(j * 10 + S[i] - '0') % 13] %= MOD;
      }
    } else {
      for (int j = 0; j < 13; j++){
        for (int k = 0; k < 10; k++){
          dp[i + 1][(j * 10 + k) % 13] += dp[i][j];
          dp[i + 1][(j * 10 + k) % 13] %= MOD;
        }
      }
    }
  }
  cout << dp[N][5] << endl;
}