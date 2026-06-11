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
vector<i64> a, b;
int main() {
  cin >> n;
  read_n(a, n);
  read_n(b, n);

  queue<i64> que;
  for (i64 i = 0; i < n; ++i) {
    que.push(i);
  }

  i64 ans = 0;
  while (!que.empty()) {
    i64 i = que.front();
    que.pop();
    i64 l = (i - 1 + n) % n,
        r = (i + 1) % n,
        x = b[i] - a[i],
        y = b[l] + b[r];
    if (x >= y) {
      b[i] = x % y + a[i];
      ans += x / y;
      que.push(l);
      que.push(r);
    }
  }

  for (i64 i = 0; i < n; ++i) {
    if (a[i] != b[i]) ans = -1;
  }
  
  cout << ans << endl;
  return 0;
}

