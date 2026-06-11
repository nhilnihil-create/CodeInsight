#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int H, W; cin >> H >> W;
  string S[H]; for (int i = 0; i < H; i++) cin >> S[i];
  int L[H][W];

  for (int i = 0; i < H; i++) {
    int l = 0, r = 0, a = 0;

    while (r != W) {
      if (S[i][r] == '.') {
        if (a == 0) l = r;
        a++;

        if (r == W-1) {
          for (int j = l; j < r+1; j++) {
            L[i][j] = a-1;
          }
        }
      } else {
        if (a != 0) {
          for (int j = l; j < r; j++) {
            L[i][j] = a-1;
          }
        }

        a = 0;
        L[i][r] = -1; 
      }
      r++;
    }

  }

  for (int i = 0; i < W; i++) {
    int u = 0, d = 0, a = 0;

    while (d != H) {
      if (S[d][i] == '.') {
        if (a == 0) u = d;
        a++;

        if (d == H-1) {
          for (int j = u; j < d+1; j++) {
            L[j][i] += a;
          }
        }
      } else {
        if (a != 0) {
          for (int j = u; j < d; j++) {
            L[j][i] += a;
          }
        }

        a = 0;
        L[d][i] = -1; 
      }
      d++;
    }

  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, L[i][j]);
    }
  }

  cout << ans << endl;

  return 0;
}