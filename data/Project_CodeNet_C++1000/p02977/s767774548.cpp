#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 n;
int main() {
  cin >> n;
  for (i64 i = 1; i <= n; i <<= 1) {
    if (i == n) {
      cout << "No\n";
      return 0;
    }
  }
  
  vector<pair<i64, i64>> e;

  if (n % 2 == 0) {
    i64 u = 1;
    for (; (u << 1) < n; u <<= 1);
    i64 v = n + ((n & ~u) | 1);
    e.emplace_back(n, u);
    e.emplace_back(n + n, v);
  }

  e.emplace_back(3, n + 1);
  for (i64 i = 2; i < n; i += 2) {
    e.emplace_back(1, i);
    e.emplace_back(i, i + 1);
    e.emplace_back(1, n + i + 1);
    e.emplace_back(n + i + 1, n + i);
  }

  cout << "Yes\n";
  for (auto p : e) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
