#include <bits/stdc++.h>
using namespace std;

const long mod = 998244353;
const long inv = mod / 2 + 1;
int n, s;
int a[3000];
long dp[3001];
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  dp[0] = 1;
  for (int i = 0; i < n; ++i) dp[0] = dp[0] * 2 % mod;
  for (int i = 0; i < n; ++i) {
    for (int k = s; k >= 0; --k) {
      if (k + a[i] > s) continue;
      dp[k + a[i]] = (dp[k + a[i]] + dp[k] * inv) % mod;
    }
  }
  cout << dp[s] << endl;
}