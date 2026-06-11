#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

pair<ll, int> solve(int a, int b, ll c) {
  ll res = 0;
  vector<ll> mem_c(10, -1), mem_res(10, -1);
  while (c > 0) {
    if (mem_c[a] != -1) {
      ll use_c = mem_c[a] - c;
      ll cost = res - mem_res[a];
      ll cnt = c / use_c;
      res += cnt * cost;
      c -= cnt * use_c;
      auto v = solve(a, b, c);
      res += v.fst;
      a = v.snd;
      break;
    }
    mem_c[a] = c;
    mem_res[a] = res;
    int s = a + b;
    ++res;
    --c;
    while (s > 9) {
      int ns = (s / 10) + (s % 10);
      ++res;
      s = ns;
    }
    a = s;
  }
  return {res, a};
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int M;
  while (cin >> M) {
    ll res = 0;
    int a = 0;
    for (int i = 0; i < M; i++) {
      int d;
      ll c;
      cin >> d >> c;
      auto r = solve(a, d, c);
      res += r.fst;
      a = r.snd;
    }
    cout << res - 1 << endl;
  }
  return 0;
}
