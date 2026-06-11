#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
#define MOD 1000000007
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int p = 13;
  int ten = 1;
  int q = 0;

  vector<vector<int>> d(n + 1, vector<int>(13, 0));
  vector<vector<int>> dp(n + 1, vector<int>(13, 0));
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '?') {
      for(int j = 0; j <= 9; j++) {
        if(i == n - 1) {
          int a = j * ten % p;
          d[i][a] = 1;
          dp[i][a] = 1;
          dp[i][a] %= MOD;
        } else {
          int a = j * ten % p;
          for(int k = 0; k < 13; k++) {
            if(d[i + 1][k] == 1) {
              d[i][(a + k) % p] = 1;
              dp[i][(a + k) % p] += dp[i + 1][k];
              dp[i][(a + k) % p] %= MOD;
            }
          }
        }
      }
      q++;
    } else {
      int a = (s[i] - '0') * ten % p;
      if(i == n - 1) {
        d[i][a] = 1;
        dp[i][a] = 1;
      } else {
        for(int k = 0; k < 13; k++) {
          if(d[i + 1][k] == 1) {
            d[i][(a + k) % p] = 1;
            dp[i][(a + k) % p] += dp[i + 1][k];
            dp[i][(a + k) % p] %= MOD;
          }
        }
      }
    }
    ten *= 10;
    ten %= p;
  }
  cout << dp[0][5] << '\n';
  return 0;
}