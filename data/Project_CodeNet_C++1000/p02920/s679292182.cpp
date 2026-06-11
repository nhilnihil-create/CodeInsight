// 2020-08-15 00:13:45
#include<bits/stdc++.h>
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

void answer() {
  int n;
  cin >> n;
  vector<int> a(1<<n), s;
  rep(i, 1<<n) cin >> a[i];
  sort(RALL(a));
  s.push_back(a[0]);
  a[0] = -1;
  rep(_, n) {
    vector<int> p = s;
    sort(ALL(p));
    rep(i, a.size()) {
      if(p.size() == 0) break;
      if(a[i] == -1) continue;
      if(p.back() > a[i]) {
        p.pop_back();
        s.push_back(a[i]);
        a[i] = -1;
      }
    }
    if(p.size() > 0) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}