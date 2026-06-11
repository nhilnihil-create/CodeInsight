#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  for (int i=0; i<H; i++) cin >> s[i];
  vector<vector<int>> dp(H, vector<int>(W, INT_MAX));
  if (s[0][0]=='#') dp[0][0] = 1;
  else dp[0][0] = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      for (int dir = 0; dir<2; dir++) {
        int ni = i+dx[dir], nj = j+dy[dir];
        if (ni>=H||nj>=W) continue;
        int add = 0;
        if (s[ni][nj]=='#'&&s[i][j]=='.') add = 1;
        dp[ni][nj] = min(dp[ni][nj], dp[i][j]+add);
      }
    }
  }
  cout << dp[H-1][W-1] << endl;
  return 0;
}