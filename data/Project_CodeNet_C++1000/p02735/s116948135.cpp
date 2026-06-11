#include <iostream>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  string S[H];
  for (int i = 0; i < H; i++) cin >> S[i];
  
  int dp[H][W];
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) dp[i][j] = 1000000;
  if (S[0][0] == '#') dp[0][0] = 1;
  else dp[0][0] = 0;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (i == 0 && j == 0) continue;
      if (i == 0) {
        if (S[i][j] == '#' && S[i][j - 1] == '.') dp[i][j] = dp[i][j - 1] + 1;
        else dp[i][j] = dp[i][j - 1];
      }
      else if (j == 0) {
        if (S[i][j] == '#' && S[i - 1][j] == '.') dp[i][j] = dp[i - 1][j] + 1;
        else dp[i][j] = dp[i - 1][j];
      }
      else {
        if (S[i][j] == '#' && S[i - 1][j] == '.') dp[i][j] = dp[i - 1][j] + 1;
        else dp[i][j] = dp[i - 1][j];
        if (S[i][j] == '#' && S[i][j - 1] == '.') dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        else dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}