#include <iostream>
using namespace std;

const int MAX = 2000;
const long long MOD = 1e9 + 7;
long long dp[MAX];

int main() {
  int S;
  cin >> S;
  dp[0] = 1;

  for (int i = 1; i <= S; i++) {
    if (i < 3) {
      dp[i] = 0;
    } else {
      dp[i] = (dp[i-3] + dp[i-1]) % MOD;
    }
  }

  cout << dp[S] << endl;
  return 0;
}
