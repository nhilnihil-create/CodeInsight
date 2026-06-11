#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> ng(n,false);
  rep(i,m) {
    int a;
    cin >> a;
    ng[a] = true;
  }
  vector<int> dp(n+1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    if(ng[i]) continue;
    dp[i] += dp[i-1];
    if(i > 1) dp[i] += dp[i-2];
    dp[i] %= mod;
  }
  cout << dp[n] << endl;
  return 0;
}