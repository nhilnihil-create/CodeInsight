#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i, 0, h) cin >> v[i];

  vector<vector<int>> acch(h, vector<int>(w, 0));
  vector<vector<int>> accw = acch;

  rep(i, 0, h) {
    int now = 0;
    rep(j, 0, w) {
      if (v[i][j] == '#') {
        now = 0;
      } else {
        now++;
        accw[i][j] = now;
      }
    }
    now = 0;
    repr(j, 0, w) {
      if (v[i][j] == '#') {
        now = 0;
      } else {
        now++;
        accw[i][j] += now - 1;
      }
    }
  }

  rep(i, 0, w) {
    int now = 0;
    rep(j, 0, h) {
      if (v[j][i] == '#') {
        now = 0;
      } else {
        now++;
        acch[j][i] = now;
      }
    }
    now = 0;
    repr(j, 0, h) {
      if (v[j][i] == '#') {
        now = 0;
      } else {
        now++;
        acch[j][i] += now - 1;
      }
    }
  }

  int ans = 0;
  rep(i, 0, h) {
    rep(j, 0, w) { chmax(ans, acch[i][j] + accw[i][j]); }
  }

  cout << ans - 1 << endl;
}
