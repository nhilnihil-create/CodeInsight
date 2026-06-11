#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P  = pair<int, int>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  deque<P> deq;
  vector<vector<int>> grid(h, vector<int>(w, INF));
  grid[0][0] = (s[0][0] == '#');
  deq.push_front({0, 0});
  while (!deq.empty()) {
    int x, y;
    tie(x, y) = deq.front();
    deq.pop_front();
    rep(i, 2) {
      if (x+dx[i] < 0 || y+dy[i] < 0 || x+dx[i] >= h || y+dy[i] >= w)
        continue;
      if (s[x+dx[i]][y+dy[i]] == '.' || s[x+dx[i]][y+dy[i]] == s[x][y]) {
        if (chmin(grid[x+dx[i]][y+dy[i]], grid[x][y]))
          deq.push_front({x+dx[i], y+dy[i]});
      } else {
        if (chmin(grid[x+dx[i]][y+dy[i]], grid[x][y]+1))
          deq.push_back({x+dx[i], y+dy[i]});
      }
    }
  }
  cout << grid[h-1][w-1] << endl;
  return 0;
}