// 2020-08-18 23:00:27
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
  ll k, q;
  cin >> k >> q;
  vector<ll> d(k);
  rep(i, k) cin >> d[i];
  rep(_, q) {
    ll n, x, m;
    cin >> n >> x >> m;
    ll y = x, z = 0;
    rep(i, k) {
      ll cnt = (n-1) / k;
      if(i < ((n-1) % k)) cnt++;
      if((d[i] % m) == 0) z += cnt;
      else y += cnt * (d[i] % m);
    }
    cout << (n - 1) - (y / m - x / m) - z << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}