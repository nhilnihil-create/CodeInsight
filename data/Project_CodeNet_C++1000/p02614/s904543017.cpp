#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> fi(H);
  for (int i = 0; i < H; ++i) cin >> fi[i];
  
  int res = 0;
  for (int bh = 0; bh < (1<<H); ++bh) {
    for (int bw = 0; bw < (1<<W); ++bw) {
      int cnt = 0;
      for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
          if (bh & (1<<h)) continue;
          if (bw & (1<<w)) continue;
          if (fi[h][w] == '#') ++cnt;
        }
      }
      if (cnt == K) ++res;
    }
  }
  cout << res << endl;
}