// 2020-07-24 05:57:33
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
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
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n;
  cin >> n;
  set<int> zero;
  zero.insert(0);
  zero.insert(n+1);
  vector<int> mp(n+2, 0);
  REPC(i, 1, n) {
    ll p;
    cin >> p;
    if(p < n) mp[p] = i;
    else zero.insert(i);
  }
  ll ans = 0;
  REPCM(i, n-1, 1) {
    ll x = i;
    ll idx = mp[x];
    ll l2, l1, r1, r2;
    {
      auto itr = zero.upper_bound(idx);
      r1 = *itr;
      if(r1 <= n) r2 = *(next(itr));
      else r2 = r1+1;
      itr--;
      l1 = *itr;
      if(1 <= l1) l2 = *(prev(itr));
      else l2 = l1-1;
    }
    if(1 <= l1) ans += x * (l1 - l2) * (r1 - idx);
    if(r1 <= n) ans += x * (idx - l1) * (r2 - r1);
    zero.insert(idx);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}