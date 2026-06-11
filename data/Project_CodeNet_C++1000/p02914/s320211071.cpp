#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  valarray<uint64_t> a(n);
  uint64_t allxor = 0;

  for (auto&& e : a) {
    cin >> e;
    allxor ^= e;
  }
  a &= ~allxor;

  int j, rank = 0;

  for (int i = 59; i >= 0; i--) {
    for (j = rank; j < n; j++) {
      if ((a[j] & (1ULL << i)) != 0) break;
    }
    if (j == n) continue;
    if (j > rank) a[rank] ^= a[j];
    for (j = rank + 1; j < n; j++) {
      a[j] = min(a[j], a[j] ^ a[rank]);
    }
    rank++;
  }

  uint64_t x = 0;

  for (auto&& e : a) {
    x = max(x, x ^ e);
  }

  cout << x + x + allxor << endl;
}
