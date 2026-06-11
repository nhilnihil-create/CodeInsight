#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> mat(H);
  for (int i = 0; i < H; ++i) {
    cin >> mat[i];
  }
  int dp[H][W];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i + j == 0) {
        dp[0][0] = (mat[0][0] == '#');
      } else {
        dp[i][j] = 1e9;
        if (i > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + (mat[i - 1][j] == '.' && mat[i][j] == '#'));
        }
        if (j > 0) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + (mat[i][j - 1] == '.' && mat[i][j] == '#'));
        }
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
  return 0;
}
  