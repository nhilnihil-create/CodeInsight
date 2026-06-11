#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
// x[H][W]
// 1: accessible
// INF: not arrived
// -1: can't access
int a[20][20];
int H, W;

void dfs(int x, int y) {
  int moveX[4] = { 1, 0, -1, 0 };
  int moveY[4] = { 0, 1, 0, -1 };
  a[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = moveX[i]+x;
    int ny = moveY[i]+y;
    if (a[ny][nx] == INF && nx >= 0 && nx < W && ny >= 0 && ny < H) {
      dfs(nx, ny);
    }
  }
}

signed main() {
  while (cin>>W>>H, W+H!=0) {
    int startX, startY;
    for (int i = 0LL; i < H; i++) {
      for (int j = 0LL; j < W; j++) {
        char c; cin >> c;
        if (c == '.') {
          a[i][j] = INF;
        } else if (c == '#') {
          a[i][j] = -1;
        } else {
          a[i][j] = INF;
          startX = j;
          startY = i;
        }
      }
    }
    dfs(startX, startY);
    
    int ans = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (a[i][j] == 1) ans++;
      }
    }

    cout << ans << endl;
  }
}

