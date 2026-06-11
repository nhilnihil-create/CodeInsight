#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
  int N;
  int S;
  cin >> N >> S;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int dp[N+1][S+1]; //dp[i][j] i番目までの数字の部分和jの組み合わせ数
  for (int i = 0; i <= S; i++) {
    dp[0][i]=0;
  }
  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i+1][j] = 2*dp[i][j]%MOD;
      if (j-A[i]>=0 && dp[i][j-A[i]]>0) {
        dp[i+1][j] += dp[i][j-A[i]];
        dp[i+1][j] %= MOD;
      }
    }
  }
  
  cout << dp[N][S] << endl;

  return 0;
}