#include <bits/stdc++.h>
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, irep, _rep)(__VA_ARGS__)
#define rep1(...) GET_REP(__VA_ARGS__, irep1, _rep1)(__VA_ARGS__)
#define _rep(i, n) irep (i, 0, n)
#define _rep1(i, n) irep1(i, 1, n)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define irep1(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(X, x) for (auto &&X : x)
#define all(x) begin(x), end(x)
#define debug(x) cout << #x " => " << (x) << endl
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
#endif
using lint = long long;
constexpr int MOD = (int)1e9 + 7;
constexpr double EPS = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

int main(void) {
  lint t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  lint aa1 = a1 * t1, aa2 = a2 * t2, bb1 = b1 * t1, bb2 = b2 * t2;
  if (aa1 + aa2 == bb1 + bb2) {
    cout << "infinity" << endl;
    return 0;
  }
  if (aa1 + aa2 < bb1 + bb2) {
    swap(aa1, bb1);
    swap(aa2, bb2);
  }
  if (aa1 > bb1) {
    cout << 0 << endl;
    return 0;
  }
  lint cnt = 0;
  lint d1 = aa1 - bb1, d2 = aa1 + aa2 - bb1 - bb2;
  cnt += -d1 / d2;
  cnt += -d1 / d2 + 1;
  if (d1 % d2 == 0) --cnt;
  cout << cnt << endl;
  return 0;
}