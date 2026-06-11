#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define I_1000000007 (1000000007)
#define I_998244353   (998244353)
#define I_INF             (1<<28)
#define L_INF           (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"
template<class T> inline bool chmin(T& a, const T& b) {
  if (a > b) { a = b; return true; } else return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
  if (a < b) { a = b; return true; } else return false;
}

namespace solver {
  using namespace std;
  using ll = long long;

  ll N;

  void init() {
    cin >> N;
  }

  vector<ll> factors(ll n) {
    vector<ll> res;
    int lim = (int)min(n, (ll)sqrt(n)+2);
    REP(i, 1, lim) {
      if(i > n/i) break;
      else if(n%i==0) {
        res.push_back(i);
        if(i != n/i) res.push_back(n/i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }

  void solve() {
    if(N<=2) {
      cout << 1 << "\n";
      return;
    }
    vector<ll> f1 = factors(N-1);
    vector<ll> f2 = factors(N);
    ll ans = 0;
    ans += f1.size() - 1;
    for(const auto& a : f2) {
      if(a == 1) continue;
      ll n = N;
      while(n % a == 0) n /= a;
      if(n > a && (n % a == 1)) ans++;
      else if(n == 1) ans++;
    }
    cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}