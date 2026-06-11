#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int64_t sum = 0, mask = 0;
  for (int i = 0; i < n; ++i) {
    sum ^= a[i];
    mask |= a[i];
  }
  int64_t res = 0, ad = 0;
  for (int bit = 59; bit >= 0; bit--) {
    if (sum >> bit & 1) {
      res += (1LL << bit);
      continue;
    }
    if ((mask >> bit & 1) == 0) continue;
    ad |= (1LL << bit);
  }
  vector<int64_t> basis;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    a[i] &= ad;
    sum ^= a[i];
  }
  int pos = 0;
  for (int bit = 59; bit >= 0; --bit) {
    int p = -1;
    for (int i = pos; i < n; ++i) {
      if (a[i] >> bit & 1) p = i;
    }
    if (p == -1) continue;
    swap(a[p], a[pos]);
    for (int i = 0; i < n; ++i) {
      if (i == pos) continue;
      if (a[i] >> bit & 1) a[i] ^= a[pos];
    }
    pos++;
  }
  int64_t k = 0;
  for (int i = 0; i < n; ++i) k ^= a[i];
  cout << res + ((sum ^ k) + k) << "\n";
  return 0;
}
