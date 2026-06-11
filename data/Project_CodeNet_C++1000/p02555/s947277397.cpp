#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
  int s;
  cin >> s;
  ll dp[s + 1] = {}, x = 0;
  dp[0] = 1;

  for (int i = 1; i <= s; ++i) {
    if (i - 3 >= 0) (x += dp[i - 3]) %= mod;
    dp[i] = x;
  }

  cout << dp[s] << endl;
  return 0;
}