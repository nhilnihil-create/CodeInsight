#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e+9 + 7;

int main() {
  int N, M, a;
  cin >> N >> M;
  vector<bool> broken(N + 1, false);
  rep(i, M) {
    cin >> a;
    broken[a] = true;
  }

  vector<int> dp(N + 1, 0);
  dp[0] = 1;
  dp[1] = broken[1] ? 0 : 1;
  for (int i = 2; i <= N; i++) {
    if (broken[i]) continue;
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= MOD;
  }
  cout << dp[N] << endl;

  return 0;
}