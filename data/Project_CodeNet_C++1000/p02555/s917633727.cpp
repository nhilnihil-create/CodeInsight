#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;
long long dp[N];

signed main() {
  int s;
  cin >> s;

  dp[0] = 1;
  for (int i = 0; i <= s; i++) {
    for (int add = 3; add <= s; add++) {
      if(i - add < 0) continue;
      dp[i] += dp[i - add];
      dp[i] %= mod;
    }
  }

  cout << dp[s] << '\n';

}