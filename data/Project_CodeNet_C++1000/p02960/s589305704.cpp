#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll> > dp(n + 1, vector<ll>(13));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= 12; ++j) {
      if (s[i] == '?') {
        for (int k = 0; k <= 9; ++k) {
          dp[i + 1][((10 * j) + k) % 13] += dp[i][j];
          dp[i + 1][((10 * j) + k) % 13] %= MOD;
        }
      } else {
        int num = s[i] - '0';
        dp[i + 1][((10 * j) + num) % 13] += dp[i][j];
        dp[i + 1][((10 * j) + num) % 13] %= MOD;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}