// 2020-06-23 21:17:58
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

bool ok(ll n, ll k) {
  if(n == 1) return true;
  if(n < k) return false;
  if(n % k) return ok(n - k * (n / k), k);
  else return ok(n / k, k);
}
void answer() {
  ll n;
  cin >> n;
  vector<ll> ans;
  vector<ll> ks1 = prime::divisors(n);
  for(const ll k : ks1) if(2 <= k && k <= n) {
    if(ok(n, k)) ans.emplace_back(k);
  }
  vector<ll> ks2 = prime::divisors(n-1);
  for(const ll k : ks2) if(2 <= k && k <= n) {
    ans.emplace_back(k);
  }
  sort(ALL(ans));
  ans.erase(unique(ALL(ans)), ans.end());
  cout << ans.size() << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}