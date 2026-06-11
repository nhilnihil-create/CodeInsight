#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
inline char getcha() {
  if (ci - cn == cm) {
    fread(cn, 1, cm, stdin);
    ci = cn;
  }
  return *ci++;
}
inline int getint() {
  int A = 0;
  if (ci - cn + 16 > cm)
    while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
  else
    while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
  return A;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int n = getint(), m = getint();
  const int mx = 40;
  vector<vector<int>> ex(mx);
  for (int i = 0, a, a_; i < n; i++) {
    a = getint();
    a_ = a;
    int cnt = 0;
    while (a > 0) {
      a /= 2;
      cnt++;
    }
    ex[cnt].emplace_back(a_);
  }
  for (int i = mx - 1; i > 0 && m > 0; i--) {
    if ((int)ex[i].size() <= m) {
      for (auto&& e : ex[i]) {
        e /= 2;
        ex[i - 1].emplace_back(e);
        e = 0;
      }
      m -= (int)ex[i].size();
    } else {
      sort(ex[i].begin(), ex[i].end(), greater<int>());
      for (int j = 0; j < m; j++) {
        ex[i][j] /= 2;
      }
      m = 0;
    }
  }
  long long ans = 0;
  for (int i = 0; i < mx; i++) {
    for (auto&& e : ex[i]) {
      ans += e;
    }
  }
  printf("%lld", ans);
  return 0;
}