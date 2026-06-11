#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MAX = 105;

char inp[MAX][MAX];
int H, W;

bool empty(int x, int y) {
  if (inp[x][y] == '#') return false;
  return true;
}

bool okay(int x, int y) { return x >= 0 && x < H && y >= 0 && y < W; }

int dp[MAX][MAX];

bool can[MAX][MAX][MAX][MAX];

int dx[] = {0, +1};
int dy[] = {+1, 0};

void Visit(int startx, int starty, int x, int y) {
  can[startx][starty][x][y] = true;

  for (int i = 0; i < 2; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!okay(nx, ny) || can[startx][starty][nx][ny]) continue;
    if (empty(nx, ny) == empty(x, y)) Visit(startx, starty, nx, ny);
  }
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    scanf("%s", inp[i]);
  }

  if (!empty(0, 0)) {
    dp[0][0] = 1;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      Visit(i, j, i, j);
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i == 0 && j == 0) continue;
      dp[i][j] = MAX * MAX;
      int add = 0;
      if (!empty(i, j)) add++;

      for (int k = 0; k <= i; k++)
        for (int l = 0; l <= j; l++) {
          if (!can[k][l][i][j]) continue;
          if (k == 0 && l == 0) {
            dp[i][j] = min(dp[i][j], add);
          }
          for (int d = 0; d < 2; d++) {
            int lastx = k - dx[d];
            int lasty = l - dy[d];
            if (!okay(lastx, lasty)) continue;
            dp[i][j] = min(dp[i][j], add + dp[lastx][lasty]);
          }
        }
    }
  }
  cout << dp[H - 1][W - 1] << endl;

  return 0;
}