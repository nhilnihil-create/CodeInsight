#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int INF = 1<<10;

int H, W, N;
char field[1010][1010];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int vt[1010][1010];
int sx, sy;
int cnt = 0;

int bfs() {
  for (int i = 1; i <= N; i++) {
    queue<P> q;
    for (int y = 0; y < H; y++)
      for (int x = 0; x < W; x++) vt[y][x] = INF;
    q.push(P(sx, sy));
    vt[sy][sx] = 0;
    bool flag = false;

    while (!q.empty() && !flag) {
      int x = q.front().first;
      int y = q.front().second;
      int c = vt[y][x];
      q.pop();
      for (int j = 0; j < 4; j++) {
        int nx = x + dx[j], ny = y + dy[j];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H || vt[ny][nx] != INF ||
            field[ny][nx] == 'X') continue;
        if (field[ny][nx] == '0' + i) {
          sx = nx; sy = ny;
          cnt += c + 1;
          flag = true;
          break;
        }
        q.push(P(nx, ny));
        vt[ny][nx] = c + 1;
      }
    }
  }
}

int main() {
  cin >> H >> W >> N;
  for (int y = 0; y < H; y++) {
    cin >> field[y];
    for (int x = 0; x < W; x++) {
      if (field[y][x] == 'S') {
        sx = x; sy = y;
      }
    }
  }

  bfs();
  cout << cnt << endl;

  return 0;
}