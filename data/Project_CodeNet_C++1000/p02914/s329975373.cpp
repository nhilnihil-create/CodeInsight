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

int bits = 62;

template <int bits = 62>
ll solveXorMax(vector<ll> A) {
  int N = A.size(), r = 0;
  for (int b = bits - 1; b >= 0; b--) {
    int p = -1;
    for (int i = r; i < N; i++) {
      if ((A[i] >> b) & 1) {
        p = i;
        break;
      }
    }
    if (p == -1) continue;
    swap(A[p], A[r]);
    for (int i = 0; i < N; i++) {
      if (i != r && ((A[i] >> b) & 1)) A[i] ^= A[r];
    }
    ++r;
  }
  ll res = 0;
  for (ll x : A) {
    if ((res ^ x) > res) res ^= x;
  }
  return res;
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N;
  while (cin >> N) {
    vector<ll> A(N);
    for (ll& x : A) cin >> x;
    ll S = 0;
    for (ll x : A) S ^= x;
    vector<ll> B(N);
    int k = 0;
    for (int b = bits - 1; b >= 0; b--) {
      if ((S >> b) & 1) continue;
      for (int i = 0; i < N; i++) B[i] = B[i] * 2 + ((A[i] >> b) & 1);
      ++k;
    }
    ll mx = solveXorMax(B);
    ll res = 0;
    for (int b = bits - 1; b >= 0; b--) {
      if ((S >> b) & 1) {
        res *= 2;
      } else {
        --k;
        res = res * 2 + ((mx >> k) & 1);
      }
    }
    res = res * 2 + S;
    cout << res << endl;
  }
  return 0;
}
