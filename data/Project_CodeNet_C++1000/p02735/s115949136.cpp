#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];

  vector<vector<int>> DP(H+1, vector<int>(W+1, H*W+1));
  DP[0][0] = (S[0][0] == '#') ? 1 : 0;
  for(int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      int nx = x + 1;
      if (nx < W) {
        int nx_s = (S[y][x] == '.') && (S[y][nx] == '#');
        DP[y][nx] = min(DP[y][nx], DP[y][x] + nx_s);
      }
      int ny = y + 1;
      if (ny < H) {
        int ny_s = (S[y][x] == '.') && (S[ny][x] == '#');
        DP[ny][x] = min(DP[ny][x], DP[y][x] + ny_s);
      }
    }
  }
  cout << DP[H-1][W-1] << endl;
  return 0;
}