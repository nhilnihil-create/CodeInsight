#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> s[i][j];

  queue<P> Q, R;
  vector<vector<int>> dist(h, vector<int>(w, -1));
  if (s[0][0] == '.') {
    Q.push(make_pair(0, 0));
    dist[0][0] = 0;
  }
  else {
    R.push(make_pair(0, 0));
    dist[0][0] = 1;
  }
  int d = 0;
  
  while (dist[h-1][w-1] == -1) {
    char path;
    if (d % 2 == 0) path = '.';
    else path = '#';
    while (Q.size()) {
      P p = Q.front();
      Q.pop();
      int x = p.first;
      int y = p.second;
      rep(i, 2) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= h || ny >= w) continue;
        if (dist[nx][ny] != -1) continue;
        if (s[nx][ny] != path) {
          R.push(make_pair(nx, ny));
          dist[nx][ny] = d + 1;
          continue;
        }
        Q.push(make_pair(nx, ny));
        dist[nx][ny] = d;
      }
    }
    ++d;
    while (R.size()) {
      P p = R.front();
      R.pop();
      Q.push(p);
    }
  }

  int ans = (dist[h-1][w-1] + 1) / 2;

  cout << ans << endl;

  return 0;
}