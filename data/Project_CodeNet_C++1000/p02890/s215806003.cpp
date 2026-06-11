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
template<class T> T iabs(const T& x) { return max(x, -x); }
// #define abs gabs

template<class F>
i64 bisect(i64 l, i64 r, F f) { // (l, r]
  if (r - l <= 1) return r;
  i64 m = l + (r - l) / 2;
  return f(m) ? bisect(l, m, f) : bisect(m, r, f);
}

template<class F>
i64 bisect_left(i64 l, i64 r, F f) {
  return bisect(l, r, [=](i64 x) { return !f(x); }) - 1;
}
int main() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        b[a]++;
    }
    sort(begin(b), end(b));
    auto it = remove(begin(b), end(b), 0);
    b.erase(it, end(b));
    int m = b.size();
    vector<int> s(m + 1);
    for (int i = 1; i <= m; ++i) {
        s[i] = s[i - 1] + b[i - 1];
    }
    
    for (int k = 1; k <= n; ++k) {
        int ans = bisect_left(0, n + 1, [&](int x) {
            int i = lower_bound(begin(b), end(b), x) - begin(b);
            int t = s[i] + (m - i) * x;
            return t / k >= x;
        });
        cout << ans << '\n';
    }
    return 0;
}