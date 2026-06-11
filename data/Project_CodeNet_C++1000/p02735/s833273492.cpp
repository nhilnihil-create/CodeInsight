#include <iostream>
#include <queue>

#define INF (1<<28)

using namespace std;

#define MAX_H 100
#define MAX_W 100

int H, W;
char S[MAX_H][MAX_W];

int dx[] = {0, 1}, dy[] = {1, 0};

struct P { int x, y, current, flip; };

bool solve() {
  queue<P> q;

  int used[MAX_H][MAX_W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      used[i][j] = INF;
    }
  }

  q.push(P{0, 0, S[0][0], S[0][0] == '.' ? 0 : 1});

  int ans = INF;

  while (!q.empty()) {
    P p = q.front(); q.pop();
    if (p.flip >= ans) { continue; }
    if (p.x == W-1 && p.y == H-1) { ans = p.flip; continue; }

    for (int i = 0; i < 2; i++) {
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if (0 <= nx && nx < W && 0 <= ny && ny < H) {
        if (S[ny][nx] == p.current) {
          if (p.flip < used[ny][nx]) {
            used[ny][nx] = p.flip;
            q.push(P{nx, ny, p.current, p.flip});
          }
        } else {
          int nc = p.current == '.' ? '#' : '.';
          int nf = p.current == '.' ? (p.flip+1) : p.flip;
          if (nf < ans && nf < used[ny][nx]) {
            used[ny][nx] = nf;
            q.push(P{nx, ny, nc, nf});
          }
        }
      }
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> H >> W;
  string s;
  for (int i = 0; i < H; i++) {
    cin >> s;
    if (s.size() == 0) cin >> s;
    for (int j = 0; j < W; j++) {
      S[i][j] = s[j];
    }
  }
  solve();
}
