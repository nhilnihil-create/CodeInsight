#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  fenwick_tree<int64_t> bit(n);
  for (int i = 0; i < n; i++) {
    bit.add(i, a.at(i));
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 0) {
      int p, x;
      cin >> p >> x;
      bit.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << bit.sum(l, r) << endl;
    }
  }
}
