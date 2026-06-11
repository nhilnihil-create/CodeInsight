#include <bits/stdc++.h>

#include <atcoder/all>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick_tree<long long> fw(n);
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    fw.add(i, a);
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t) {
      cout << fw.sum(x, y) << '\n';
    } else {
      fw.add(x, y);
    }
  }
  return 0;
}