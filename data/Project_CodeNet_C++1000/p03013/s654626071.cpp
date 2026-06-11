#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;

  vector<bool> broken(N + 1);
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  vector<int> dp(N + 2);
  dp[N] = 1;

  for (int i = N - 1; i >= 0; i--) {
    if (broken[i]) {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % MOD;
  }

  cout << dp[0] << endl;
}