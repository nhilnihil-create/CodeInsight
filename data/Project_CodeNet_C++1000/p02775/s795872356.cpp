#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
constexpr int N = 1000010;

ll dp[N][2];

int main() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  s += '0';

  for (int i = 0; i < N; i++) for (int j = 0; j < 2; j++) dp[i][j] = INF;

  int n = s.size();

  // 0 : 繰りさがりなし 1 : 繰りさがりあり
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      int x = s[i] - '0';
      x += j;

      for (int a = 0; a <= 9; a++) {
       int ni = i + 1;
       int nj = 0;

       int b = a - x;
       if(b < 0) {
         nj = 1;
         b += 10;
       }

       dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
      }
    }
  }

  cout << dp[n][0] << '\n';
}