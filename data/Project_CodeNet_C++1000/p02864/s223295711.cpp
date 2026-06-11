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

template <class T>
vector<T> sumup(const vector<T>& a) {
  int N = a.size();
  vector<T> res(N + 1);
  for (int i = 0; i < N; i++) res[i + 1] = res[i] + a[i];
  return res;
}

const ll INF = 1ll << 60;

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N, K;
  while (cin >> N >> K) {
    vector<ll> A(N);
    for (ll& x : A) cin >> x;
    A.insert(A.begin(), 0);
    A.push_back(0);
    N += 2;
    vec<ll, 2> dp = make_v(N, K + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
      for (int k = 0; k <= K; k++) {
        for (int j = i + 1; j < N; j++) {
          int t = j - i - 1;
          if (k + t > K) continue;
          chmin(dp[j][k + t], dp[i][k] + max(0ll, A[j] - A[i]));
        }
      }
    }
    ll res = INF;
    for (int k = 0; k <= K; k++) chmin(res, dp[N - 1][k]);
    cout << res << endl;
  }
  return 0;
}
