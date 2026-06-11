#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int x = 0) : n(x), d(x + 1) {}
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
};

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<pair<int, int>> p(n);

  long long x_max = 0;
  for (auto& pi : p) {
    cin >> pi.first >> pi.second;
    x_max = max(x_max, (long long)pi.first);
  }
  sort(p.begin(), p.end());
  BIT<long long> bit(n + 1);

  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    long long x = p[i].first;
    long long h = p[i].second;
    h -= bit.sum(i);
    if (h <= 0) continue;
    long long num = (h + a - 1) / a;
    ret += num;
    long long damage = num * a;
    bit.add(i, damage);
    int rx = min(x + 2 * d, x_max);
    int j = upper_bound(p.begin(), p.end(), make_pair(rx + 1, -1)) - p.begin();
    bit.add(j, -damage);
  }
  cout << ret << endl;
  return 0;
}
