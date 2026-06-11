// author: erray
#include<bits/stdc++.h>
 
using namespace std;

const int mod = (int) 1e9 + 7;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> vis(n);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    vis[x] = true;
  }
  vector<long long> dp(n + 3);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (vis[i]) {
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << '\n';
}