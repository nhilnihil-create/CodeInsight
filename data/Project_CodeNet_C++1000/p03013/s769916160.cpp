#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long a[100001], broken[100001] = {0}, dp[100001];
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++) broken[a[i]] = 1;
  dp[0] = 1;
  if (!broken[1]) dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-2] * (1-broken[i-2]) + dp[i-1] * (1-broken[i-1]);
    dp[i] %= 1000000007;
  }
  cout << dp[n];
  return 0;
}