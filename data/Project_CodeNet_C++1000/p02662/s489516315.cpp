#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353LL

using namespace std;

int main() {
  int n, s, a[3000];
  ll dp[3001][3001] = {};
  cin >> n >> s;
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= s; j++) {
      dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] << 1)) % MOD;
      if(j + a[i] <= s)
        dp[i + 1][j + a[i]] = (dp[i + 1][j + a[i]] + dp[i][j]) % MOD;
    }
  }
  printf("%lld\n", dp[n][s]);
}