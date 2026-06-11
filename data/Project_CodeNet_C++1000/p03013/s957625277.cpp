#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  rep(i, 0, m) {
    int a;
    cin >> a;
    dp[a] = -1;
  }

  dp[0] = 1;
  rep(i, 1, n + 1) {
    if (dp[i] == -1)
      continue;
    if (dp[i - 1] == -1 && dp[i - 2] == -1) {
      cout << 0 << endl;
      return 0;
    }

    if (i == 1)
      dp[i] = dp[i - 1];
    else {
      if (dp[i - 1] == -1)
        dp[i] = dp[i - 2];
      else if (dp[i - 2] == -1)
        dp[i] = dp[i - 1];
      else
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    dp[i] %= MOD;
  }

  cout << dp[n] << endl;
}
