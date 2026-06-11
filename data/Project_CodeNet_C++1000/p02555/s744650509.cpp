#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007; 

int main() {
  int s;
  cin >> s;
  vector<ll> dp(s+1);

  dp[0] = 1;
  for (int i = 3; i <= s; i++) {
    dp[i] = dp[i-1] + dp[i-3];
    dp[i] %= mod;
  }
  cout << dp[s];
}
