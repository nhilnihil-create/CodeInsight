// 2020-07-27 07:39:19
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

int n, p;
string s;
void answer2or5() {
  ll ans = 0;
  rep(i, n) {
    if((s[i]-'0') % p == 0) ans += i+1;
  }
  cout << ans << '\n';
}
void answer() {
  cin >> n >> p >> s;
  if(p == 2 || p == 5) {
    answer2or5();
    return;
  }
  reverse(ALL(s));
  vector<ll> mp(p, 0);
  ll c = 0, d = 1;
  rep(i, n) {
    c = (c + (s[i]-'0') * d) % p;
    mp[c]++;
    d = d * 10 % p;
  }
  ll ans = mp[0];
  for(auto x : mp) {
    ans += x * (x-1) / 2;
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}