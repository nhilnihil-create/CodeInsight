#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(h, H) cin >> S[h];

  vector<vector<int>> U(H, vector<int>(W, -1));
  vector<vector<int>> D(H, vector<int>(W, -1));
  vector<vector<int>> L(H, vector<int>(W, -1));
  vector<vector<int>> R(H, vector<int>(W, -1));
  int y, x;

  // Up and Left
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (S[h][w] == '#') continue;
      // Up
      if (U[h][w] == -1) {
        U[h][w] = 0;
        y = h + 1;
        while (y < H && S[y][w] == '.') {
          U[y][w] = U[y - 1][w] + 1;
          y++;
        }
      }
      // Left
      if (L[h][w] == -1) {
        L[h][w] = 0;
        x = w + 1;
        while (x < W && S[h][x] == '.') {
          L[h][x] = L[h][x - 1] + 1;
          x++;
        }
      }
    }
  }

  // Down and Right
  for (int h = H - 1; 0 <= h; h--) {
    for (int w = W - 1; 0 <= w; w--) {
      if (S[h][w] == '#') continue;
      // Down
      if (D[h][w] == -1) {
        D[h][w] = 0;
        y = h - 1;
        while (0 <= y && S[y][w] == '.') {
          D[y][w] = D[y + 1][w] + 1;
          y--;
        }
      }
      // Right
      if (R[h][w] == -1) {
        R[h][w] = 0;
        x = w - 1;
        while (0 <= x && S[h][x] == '.') {
          R[h][x] = R[h][x + 1] + 1;
          x--;
        }
      }
    }
  }

  int ans = 0, cnt;
  rep(h, H) rep(w, W) {
    cnt = U[h][w] + D[h][w] + L[h][w] + R[h][w] + 1;
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}