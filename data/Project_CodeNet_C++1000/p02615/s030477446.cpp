#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

template <typename T, int b = 8, int bit = sizeof(T) * 8>
void radix_sort(T* a, int n) {
  vector<T> temp(n);
  T *dist = temp.data(), *src = a;
  constexpr int mask = (1 << b) - 1;
  constexpr int kn = (bit + b - 1) / b;
  for (int k = 0; k < kn; ++k) {
    int bucket[1 << b] = {};
    int index[1 << b];
    for (int i = 0; i < n; ++i) bucket[mask & (src[i] >> (b * k))] += 1;
    index[0] = 0;
    for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
    for (int i = 0; i < n; ++i)
      dist[index[mask & (src[i] >> (b * k))]++] = src[i];
    swap(dist, src);
  }
  if (kn % 2 == 1) { memcpy(a, src, sizeof(T) * n); }
}

int a[200020];
int main() {

  int n;
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  radix_sort<int>(a, n);
  ll ans = 0;
  rep(i, 1, n) ans += a[n - 1 - i / 2];
  cout << ans << '\n';
  return 0;
}