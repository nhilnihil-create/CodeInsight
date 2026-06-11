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

const ll INF = 1ll << 62;

using P = pair<ll, int>;

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N;
  while (cin >> N) {
    vector<P> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i].fst;
      A[i].snd = i;
    }
    sort(A.rbegin(), A.rend());
    vector<ll> dp(N + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
      vector<ll> ndp(N + 1, -INF);
      for (int l = 0; l <= i; l++) {
        int r = N - (i - l) - 1;
        chmax(ndp[l + 1], dp[l] + A[i].fst * (A[i].snd - l));
        chmax(ndp[l], dp[l] + A[i].fst * (r - A[i].snd));
      }
      dp = ndp;
    }
    ll res = *max_element(dp.begin(), dp.end());
    cout << res << endl;
  }
  return 0;
}
