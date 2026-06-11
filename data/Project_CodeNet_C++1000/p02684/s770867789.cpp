#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using i64 = long long;

int main() {
  int n; i64 K; scanf("%d%lld", &n, &K);
  std::vector<int> a(n);
  for(auto& v: a) scanf("%d", &v);

  std::vector<std::vector<int>> dp(60, std::vector<int>(n));
  for(int i = 0; i < n; i++) dp[0][i] = a[i] - 1;
  for(int k = 0; k < 59; k++) for(int i = 0; i < n; i++)  dp[k + 1][i] = dp[k][dp[k][i]];

  int ans = 0;
  for(int k = 59; k >= 0; k--) {
    if(!(K >> k & 1)) continue;
    ans = dp[k][ans];
  }

  printf("%d\n", ans + 1);
  return 0;
}
