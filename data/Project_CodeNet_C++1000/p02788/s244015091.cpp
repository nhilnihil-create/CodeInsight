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
  ll n, d, a; cin >> n >> d >> a;
  vpr X(n);
  rep(i,n) {
    ll x, h; cin >> x >> h;
    X[i] = make_pair(x, h);
  }
  sort(ALL(X));
  vll sum(n+1, 0);
  ll ans = 0;
  rep(i,n) {
    if(i) sum[i] += sum[i-1];
    ll x = X[i].first, h = X[i].second;
    ll remain = h-sum[i];
    if(remain <= 0) continue;
    pr b = make_pair(x+d*2, 1e18);
    int nextX = upper_bound(ALL(X), b) - X.begin();
    ll damage = remain;
    ans += remain/a;
    if(remain%a) {
      ans++;
      damage = a*(1+remain/a);
    }
    sum[i] += damage;
    sum[nextX] -= damage;
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}