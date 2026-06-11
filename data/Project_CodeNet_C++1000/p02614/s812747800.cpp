#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  char c[H][W];

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> c[i][j];
    }
  }

  // w_bits, h_bits && 1 << iなら赤
  int ans = 0;

  for (unsigned short int h_bits = 0; h_bits < (1 << H); h_bits++) {
    for (unsigned short int w_bits = 0; w_bits < (1 << W); w_bits++) {
      int count = 0;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if (!((h_bits & (1 << i)) || (w_bits & (1 << j))) && c[i][j] == '#') count++;
        }
      }
      if (count == K) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
