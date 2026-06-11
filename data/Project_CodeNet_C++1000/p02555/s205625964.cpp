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
  int s;
  cin >> s;
  vector<ll> dp(s + 1);
  dp[0] = 1;
  for (int i = 3; i <= s; ++i) {
    for (int j = 3; j <= s; ++j) {
      if (0 <= i - j) {
        dp[i] += dp[i - j];
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[s] << endl;
  return 0;
}