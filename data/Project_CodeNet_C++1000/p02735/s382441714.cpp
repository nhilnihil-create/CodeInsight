#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int dx[] = {0, 1};
const int dy[] = {1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<int>> d(h, vector<int>(w, -1));
  queue<P> q1, q2;
  int sx = 0, sy = 0;
  int gx = h - 1, gy = w - 1;
  q1.push(P(sx, sy));
  d[0][0] = 0;
  char here = s[0][0];
  while (!q1.empty() || !q2.empty()) {
    while (!q1.empty()) {
      P p = q1.front();
      int cx = p.first, cy = p.second;
      q1.pop();
      // if (cx == gx && cy == gy) break;
      rep(i, 2) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if (d[nx][ny] != -1) continue;
        if (s[nx][ny] == here) {
          d[nx][ny] = d[cx][cy];
          q1.push(P(nx, ny));
        } else {
          d[nx][ny] = d[cx][cy] + 1;
          q2.push(P(nx, ny));
        }
      }
    }
    swap(q1, q2);
    here = (here == '.' ? '#' : '.');
    // rep(i, h) rep(j, w) printf("%+d%c", d[i][j], (j == w - 1 ? '\n' : ' '));
    // cout << endl;
  }

  int ans;
  if (s[sx][sy] == '.')
    ans = (d[gx][gy] + 1) / 2;
  else
    ans = d[gx][gy] / 2 + 1;
  cout << ans << endl;
  return 0;
}
