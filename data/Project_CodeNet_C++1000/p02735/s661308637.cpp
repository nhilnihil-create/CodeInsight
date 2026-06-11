#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

void bfs(ll h, ll w, vector<string> &grid, vector<vll> &cnt, ll ny, ll nx) {
  if (ny + 1 < h) {
    if (grid[ny + 1][nx] == '#') {
      cnt[ny + 1][nx] = min(cnt[ny + 1][nx], cnt[ny][nx] + 1);
    }
    else {
      cnt[ny + 1][nx] = min(cnt[ny + 1][nx], cnt[ny][nx]);
    }
    bfs(h, w, grid, cnt, ny + 1, nx);
  }
  if (nx + 1 < w) {
    if (grid[ny][nx + 1] == '#') {
      cnt[ny][nx + 1] = min(cnt[ny][nx + 1], cnt[ny][nx] + 1);
    }
    else {
      cnt[ny][nx + 1] = min(cnt[ny][nx + 1], cnt[ny][nx]);
    }
    bfs(h, w, grid, cnt, ny, nx + 1);
  }
  return;
}

int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> grid(h);
  for (ll i = 0; i < h; i++) cin >> grid[i];

  vector<vll> cnt(h, vll(w, inf));
  if (grid[0][0] == '#') cnt[0][0] = 1;
  else cnt[0][0] = 0;
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      if (h == 0 && w == 0) continue;
      if (grid[i][j] == '#') {
        if (i > 0 && grid[i - 1][j] == '.') {
          cnt[i][j] = min(cnt[i][j], cnt[i - 1][j] + 1);
        }
        else if (i > 0) {
          cnt[i][j] = min(cnt[i][j], cnt[i - 1][j]);
        }
        if (j > 0 && grid[i][j - 1] == '.') {
          cnt[i][j] = min(cnt[i][j], cnt[i][j - 1] + 1);
        }
        else if (j > 0) {
          cnt[i][j] = min(cnt[i][j], cnt[i][j - 1]);
        }
      }
      else {
        if (i > 0) cnt[i][j] = min(cnt[i][j], cnt[i - 1][j]);
        if (j > 0) cnt[i][j] = min(cnt[i][j], cnt[i][j - 1]);
      }
    }
  }

  cout << cnt[h - 1][w - 1] << endl;
  cerr << "fuck you" << endl;
}