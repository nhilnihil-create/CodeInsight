// 2020-07-30 22:57:28
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
namespace prime {
  bool is_prime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++) {
      if(n % i == 0) return false;
    }
    return true;
  }
  vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
      if(n % i == 0) {
        res.push_back(i);
        if(i != n / i) res.push_back(n / i);
      }
    }
    return res;
  }
  map<ll, int> prime_factors(ll n) {
    map<ll, int> res;
    if(n < 2) return res;
    for(ll i = 2; i * i <= n; i++) {
      while(n % i == 0) {
        res[i]++;
        n /= i;
      }
    }
    if(n > 1) res[n] = 1;
    return res;
  }
};

void answer() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll s = 0;
  rep(i, n) {
    cin >> a[i];
    s += a[i];
  }
  vector<ll> ds = prime::divisors(s);
  sort(RALL(ds));
  auto ok = [&](ll d) {
    auto comperator = [&](ll l, ll r) {
      ll lx = l % d;
      ll ly = d - lx;
      ll rx = r % d;
      ll ry = d - rx;
      return min(lx, ly) < min(rx, ry);
    };
    sort(ALL(a), comperator);
    ll up = 0, down = 0;
    rep(i, n-1) {
      ll x = a[i] % d;
      ll y = d - x;
      if(up + y > k) {
        down += x;
      } else if(down + x > k) {
        up += y;
      } else if(x < y) {
        down += x;
      } else if(x > y) {
        up += y;
      } else if(up < down) {
        up += y;
      } else {
        down += x;
      }
    }
    return max(up, down) <= k;
  };
  for(ll d : ds) {
    if(ok(d)) {
      cout << d << '\n';
      return;
    }
  }
  cout << 1 << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}