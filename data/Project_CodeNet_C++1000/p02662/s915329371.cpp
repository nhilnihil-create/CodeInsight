#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[3010][3010];
ll MOD = 998244353;

int main() {
  int N, S;
  cin >> N >> S;
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    for (int j = 0; j <= 3000; j++) {
      dp[i][j] = 2 * dp[i - 1][j];
      if (j - A >= 0) dp[i][j] += dp[i - 1][j - A];
      dp[i][j] %= MOD;
    }
  }
  cout << dp[N][S] << endl;
}