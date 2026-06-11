#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
constexpr int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> broken(n+1, false);
  rep(i,m) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  vector<int> dp(n+1,0);
  dp[0] = 1;
  rep(i,n) {
    dp[i] %= mod;
    if (!broken[i+1]) dp[i+1] += dp[i];
    if (!broken[i+2]) dp[i+2] += dp[i];
  }
  cout << dp[n] % mod << endl;
  return 0;
}