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
#include <random>

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
vector<i64> a;
int main() {
  cin >> n;
  read_n(a, n);

  i64 s = 0;
  for (i64 x : a) s ^= x;
  for (i64 i = 0; i < n; ++i) a[i] &= ~s;

  for (i64 i = 59, k = 0; i >= 0; --i) {
    bool f = false;
    for (i64 j = k; j < n; ++j) {
      if ((1ll << i) & a[j]) {
        swap(a[k], a[j]);
        f = true;
        break;
      }
    }
    if (!f) continue;
    for (i64 j = 0; j < n; ++j) {
      if (j != k && (1ll << i) & a[j]) a[j] ^= a[k];
    }
    ++k;
  }

  /*
  for (i64 i = 0; i < n; ++i) {
    for (i64 j = 59; j >= 0; --j) {
      cout << ((1ll << j) & a[i] ? '1' : '0');
    }
    cout << endl;
  }
  */

  i64 x = 0;
  for (i64 y : a) x ^= y;
  cout << s + 2 * x << endl;
  return 0;
}
