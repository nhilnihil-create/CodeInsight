#include <iostream>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  rep(i, 3, n + 1) dp[i] = (dp[i - 3] + dp[i - 1]) % 1000000007;
  cout << dp[n] << endl;
  return 0;
}
