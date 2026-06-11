// 2020-07-24 20:55:28
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

ll n;
bool ok(vector<ll> a, vector<ll>& f, ll k, ll x) {
  rep(i, n) {
    ll q = x / f[i];
    if(a[i] > q) {
      ll d = min(a[i] - q, k);
      a[i] -= d;
      k -= d;
    }
    if(a[i] * f[i] > x) return false;
  }
  return true;
}
void answer() {
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> f(n);
  rep(i, n) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  ll l = -1, r = 1e18;
  while(l + 1 < r) {
    ll m = (l + r) / 2;
    if(ok(a, f, k, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}