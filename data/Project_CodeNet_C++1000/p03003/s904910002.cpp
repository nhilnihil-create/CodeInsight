#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  for (int i = 0; i < N; i++){
    cin >> S[i];
  }
  vector<int> T(M);
  for (int i = 0; i < M; i++){
    cin >> T[i];
  }
  vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, 0));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      dp[i + 1][j + 1] += dp[i + 1][j];
      dp[i + 1][j + 1] += dp[i][j + 1];
      if (S[i] == T[j]){
        dp[i + 1][j + 1] ++;
      } else {
        dp[i + 1][j + 1] += MOD - dp[i][j];
      }
      dp[i + 1][j + 1] %= MOD;
    }
  }
  cout << (dp[N][M] + 1) % MOD << endl;
}