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
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
  #define debug(x) cerr << #x " => " << x << endl
#else
  #define debug(x) 0
#endif
using lint = long long;
constexpr int    INF  = 1 << 30;
constexpr lint   INFL = 1LL << 62;
constexpr int    MOD  = (int)1e9 + 7;
constexpr double EPS  = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

int main(void) {
  int n;
  cin >> n;
  int num = 1 << n;
  multiset<int> s;
  rep (i, num) {
    int x;
    cin >> x;
    s.insert(x);
  }
  multiset<int> now, left = s;
  now.insert(*left.rbegin());
  left.erase(--left.end());
  bool ok = true;
  rep (i, n) {
    vector<int> nowv(all(now));
    rep (j, nowv.size()) {
      auto itr = left.lower_bound(nowv[j]);
      if (itr == left.begin()) {
        ok = false;
        break;
      }
      --itr;
      now.insert(*itr);
      left.erase(itr);
    }
    if (!ok) break;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}