#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick_tree<long long> fw(n);
  for (int i = 0; i < n; i++) {
    long long foo;
    cin >> foo;
    fw.add(i, foo);
  }
  while (q--) {
    int op;
    cin >> op;
    if (!op) {
      int p;
      long long x;
      cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << '\n';
    }
  }
  return 0;
}
