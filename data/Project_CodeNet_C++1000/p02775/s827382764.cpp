/**
 *    author:  morato
 *    created: 25.08.2020 20:21:42
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N][2], n;
string s;

int solve(int i, int carry) {
  if (i == n) {
    return carry;
  }
  if (dp[i][carry] != -1) {
    return dp[i][carry];
  }
  int cur = (s[i] - '0') + carry;
  if (cur == 10) {
    return dp[i][carry] = solve(i + 1, 1);
  } 
  if (cur == 0) {
    return dp[i][carry] = solve(i + 1, 0);
  }
  return dp[i][carry] = min(solve(i + 1, 1) + 10 - cur, solve(i + 1, 0) + cur);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> s;
  n = s.size();
  reverse(s.begin(), s.end());
  cout << solve(0, 0) << '\n';
  return 0;
}