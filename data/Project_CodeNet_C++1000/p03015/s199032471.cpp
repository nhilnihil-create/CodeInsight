#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  string L;
  cin >> L;
  int N = L.size();
  vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++){
    if (L[i] == '0'){
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1] * 3;
    }
    if (L[i] == '1'){
      dp[i + 1][0] = dp[i][0] * 2;
      dp[i + 1][1] = dp[i][0] + dp[i][1] * 3;
    }
    dp[i + 1][0] %= MOD;
    dp[i + 1][1] %= MOD;
  }
  cout << (dp[N][0] + dp[N][1]) % MOD;
}