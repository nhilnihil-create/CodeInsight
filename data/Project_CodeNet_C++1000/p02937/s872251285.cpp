// 2020-07-24 00:32:31
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

set<int> idxs[26];
void answer() {
  string s, t;
  cin >> s >> t;
  int s_sz = s.size();
  rep(i, s_sz) {
    int ci = s[i] - 'a';
    idxs[ci].emplace(i + 1);
    idxs[ci].emplace(i + 1 + s_sz);
  }
  int cur = 1;
  ll ans = 0;
  rep(i, t.size()) {
    int ci = t[i] - 'a';
    auto itr = idxs[ci].lower_bound(cur);
    if(itr == idxs[ci].end()) {
      cout << -1 << '\n';
      return;
    } else {
      ans += *itr - cur + 1;
      cur = *itr + 1;
      if(s_sz < cur) cur -= s_sz;
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}