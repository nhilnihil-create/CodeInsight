// 2020-09-27 19:08:16
// clang-format off
#include <bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
// #include <atcoder/convolution>
// #include <atcoder/dsu>
// #include <atcoder/fenwicktree>
// #include <atcoder/lazysegtree>
// #include <atcoder/math>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/modint>
// #include <atcoder/scc>
// #include <atcoder/segtree>
// #include <atcoder/string>
// #include <atcoder/twosat>
// #include <atcoder/all>
// using namespace atcoder;

// clang-format on
void answer() {
  int x;
  cin >> x;
  cout << (2000 - x + 199) / 200 << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}