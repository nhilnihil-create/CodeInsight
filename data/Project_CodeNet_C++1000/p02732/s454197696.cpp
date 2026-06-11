// 2020-06-30 19:06:35
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
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll total = 0;
  auto calc = [](ll x) {
    return x * (x - 1) / 2;
  };
  for(auto m : mp) {
    total += calc(m.second);
  }
  rep(i, n) {
    cout << total - calc(mp[a[i]]) + calc(mp[a[i]]-1) << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}