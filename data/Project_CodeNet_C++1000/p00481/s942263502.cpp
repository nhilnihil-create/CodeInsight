#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define all(c) (c).begin(), (c).end()

#define MAX_W 1010
#define MAX_H 1010

int H, W, N;
char A[MAX_H][MAX_W];
vector<bool**> global;

pair<int, int> find_char(char c) {
  rep(y, H) {
    rep(x, W) {
      if (A[y][x] == c) return make_pair(x, y);
    }
  }
  return make_pair(-1, -1);
}

bool visited[MAX_W][MAX_H];
int bfs(int start_x, int start_y, int target_x, int target_y) {
  queue<int> q;
  rep(i, W) rep(j, H) visited[j][i] = false;

  q.push(start_x); q.push(start_y); q.push(0);
  while (!q.empty()) {
    int x  = q.front(); q.pop();
    int y  = q.front(); q.pop();
    int dist = q.front(); q.pop();

    char m = A[y][x];
    if (x == target_x && y == target_y) return dist;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    rep(i, 4) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx >= 0 && tx < W && ty >= 0 && ty < H &&
          A[ty][tx] != 'X' && !visited[ty][tx]) {
        q.push(tx);
        q.push(ty);
        q.push(dist + 1);
        visited[ty][tx] = true;
      }
    }
  }
  return INT_MIN;
}

int main() {
  cin >> H >> W >> N;
  rep(i, H) cin >> A[i];

  // ????§???????
  auto pos_s = find_char('S');
  int start_x = pos_s.first;
  int start_y = pos_s.second;

  int ans = 0;
  for (int i=1; i<=N; i++) {
    auto pos = find_char((char)((int)'0'+i));
    int tx = pos.first;
    int ty = pos.second;
    ans += bfs(start_x, start_y, tx, ty);
    start_x = tx;
    start_y = ty;
  }
  cout << ans << "\n";
  return 0;
}