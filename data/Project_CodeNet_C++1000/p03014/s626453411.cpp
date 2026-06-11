#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int head(int n) {
  string s = to_string(n);
  return s[0] - '0';
}
int tail(int n) {
  string s = to_string(n);
  return s[s.length() - 1] - '0';
}

int main() {
  int h, w;
  cin >> h >> w;
  V<string> s(h);
  rep(i, h) cin >> s[i];

  V<V<int>> r(h, V<int>(w, 0));
  V<V<int>> c(h, V<int>(w, 0));

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') continue;
      int p = (j == 0) ? 0 : r[i][j - 1];
      r[i][j] = p + 1;
    }
    for (int j = w - 2; j >= 0; j--) {
      if (s[i][j] == '#') continue;
      r[i][j] = max(r[i][j + 1], r[i][j]);
    }
  }
  rep(j, w) {
    rep(i, h) {
      if (s[i][j] == '#') continue;
      int p = (i == 0) ? 0 : c[i - 1][j];
      c[i][j] = p + 1;
    }
    for (int i = h - 2; i >= 0; i--) {
      if (s[i][j] == '#') continue;
      c[i][j] = max(c[i + 1][j], c[i][j]);
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) {
    int l = r[i][j] + c[i][j] - 1;
    ans = max(ans, l);
  }
  cout << ans << endl;
}
