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
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n, k, c; cin >> n >> k >> c;
  string s; cin >> s;
  int cur = 0;
  vector<int> l, r;
  rep(i, k) {
    while(s[cur] == 'x') cur++;
    l.emplace_back(cur), cur++;
    rep(j, c) cur++;
  }
  cur = 0;
  reverse(ALL(s));
  rep(i, k) {
    while(s[cur] == 'x') cur++;
    r.emplace_back(n-1-cur), cur++;
    rep(j, c) cur++;
  }
  reverse(ALL(r));
  rep(i, k) {
    if(l[i] == r[i]) cout << l[i]+1 << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}