// 2020-07-18 10:15:15
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
  string s;
  cin >> s;
  ll ans = 0;
  {
    ll c[3];
    memset(c, 0, sizeof c);
    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    rep(i, n) {
      c[mp[s[i]]]++;
    }
    ans = c[0] * c[1] * c[2];
  }
  rep(i, n-2) REP(j, i+1, n-1) {
    int k = j + j - i;
    if(n <= k) continue;
    ans -= (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}