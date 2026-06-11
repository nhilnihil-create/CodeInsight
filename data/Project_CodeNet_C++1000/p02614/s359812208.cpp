#include <iostream>
#include <map>
#include <string>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  char C[10][10];
  rep(i, H) {
    rep(j, W) {
      cin >> C[i][j];
    }
  }
  
  int ans = 0;
  for (int i = 0; i < 1 << H; i++) {
    for (int j = 0; j < 1 << W; j++) {
      int cnt = 0; // 黒いマスの数
      rep(k, H) {
        rep(l, W) {
          // (k, l)を判定
          if (i >> k & 1 && j >> l & 1 && C[k][l] == '#') {
            cnt++;
          } 
        }
      }
      if (cnt == K) ans++;
    }
  }
  
  cout << ans;
}

