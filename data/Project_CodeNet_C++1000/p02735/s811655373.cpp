#include <bits/stdc++.h>

using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef pair<int, int> P;
const int INF = 1e9;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
int ans[111][111];

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
      ans[i][j] = INF;
    }
  }
  ans[0][0] = 0;
  if (s[0][0] == '#') ans[0][0] = 1;
  queue<P> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 2; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || ny < 0 || w <= nx || h <= ny) continue;
      if (ans[ny][nx] < ans[p.second][p.first] + 1) continue;
      if (s[p.second][p.first] == '.' && s[ny][nx] == '#') {
        chmin(ans[ny][nx], ans[p.second][p.first] + 1);
      } else {
        chmin(ans[ny][nx], ans[p.second][p.first]);
      }
      que.emplace(nx, ny);
    }
  }
  cout << ans[h - 1][w - 1] << endl;

  return 0;
}