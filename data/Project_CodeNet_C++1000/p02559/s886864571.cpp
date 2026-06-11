#include <bits/stdc++.h>

#include <atcoder/all>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;
using namespace atcoder;

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
  if (ci - cn + 16 > cm) {
    while ((ct = getcha()) >= '0') {
      A = A * 10 + ct - '0';
    }
  } else {
    while ((ct = *ci++) >= '0') {
      A = A * 10 + ct - '0';
    }
  }
  return A;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int n = getint(), q = getint();
  fenwick_tree<long long> fw(n);
  for (int i = 0, a; i < n; i++) {
    a = getint();
    fw.add(i, a);
  }
  while (q--) {
    int t = getint(), x = getint(), y = getint();
    if (t) {
      printf("%lld\n", fw.sum(x, y));
    } else {
      fw.add(x, y);
    }
  }
  return 0;
}