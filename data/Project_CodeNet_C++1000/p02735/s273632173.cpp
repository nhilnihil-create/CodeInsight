#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int H, W; cin >> H >> W;
  string s[H];

  for (int i = 0; i < H; ++i) cin >> s[i];

  int rvn[H][W];
  memset(rvn, 0x7f, sizeof(rvn));

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (i == 0 && j == 0) {
        if (s[i][j] == '.') {
          rvn[i][j] = 0;
        } else {
          rvn[i][j] = 1;
        }
      } else if (i == 0) {
        if (rvn[i][j-1] & 1) {
          rvn[i][j] = rvn[i][j-1] + (s[i][j] == '.' ? 1 : 0);
        } else {
          rvn[i][j] = rvn[i][j-1] + (s[i][j] == '#' ? 1 : 0);
        }
      } else if (j == 0) {
        if (rvn[i-1][j] & 1) {
          rvn[i][j] = rvn[i-1][j] + (s[i][j] == '.' ? 1 : 0);
        } else {
          rvn[i][j] = rvn[i-1][j] + (s[i][j] == '#' ? 1 : 0);
        }
      } else {
        rvn[i][j] = min(rvn[i-1][j] + (((rvn[i-1][j] & 1) == 1) == (s[i][j] == '.') ? 1 : 0),
                        rvn[i][j-1] + (((rvn[i][j-1] & 1) == 1) == (s[i][j] == '.') ? 1 : 0));
      }
    }
  }

  cout << rvn[H-1][W-1]/2 + rvn[H-1][W-1]%2 << endl;

  return 0;
}