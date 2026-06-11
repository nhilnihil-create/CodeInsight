#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  vector<int64_t> bit(n + 1);
  for (int i = 0; i < n; i++) {
    int k = i + 1;
    while (k <= n) {
      bit.at(k) += a.at(i);
      k += k & -k;
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 0) {
      int p, x;
      cin >> p >> x;
      int k = p + 1;
      while (k <= n) {
        bit.at(k) += x;
        k += k & -k;
      }
    } else {
      int64_t s = 0;
      int l, r;
      cin >> l >> r;
      int k = r;
      while (k) {
        s += bit.at(k);
        k -= k & -k;
      }
      k = l;
      while (k) {
        s -= bit.at(k);
        k -= k & -k;
      }
      cout << s << endl;
    }
  }
}
