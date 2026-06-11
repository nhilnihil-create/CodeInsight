// 2020-09-16 00:25:29
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
#include <atcoder/fenwicktree>
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
using namespace atcoder;

// clang-format on
void answer() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i, n) {
    ll a;
    cin >> a;
    fw.add(i, a);
  }
  rep(i, q) {
    int c;
    cin >> c;
    if (c == 0) {
      ll p, x;
      cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}