#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007LL)
#define LINF (1LL<<60)
#define rep(i, n)   for (long long i = 0; i <  (long long)(n); i++)
#define rep1(i, n)  for (long long i = 1; i <  (long long)(n); i++)
#define rep2(i, n)  for (long long i = 2; i <  (long long)(n); i++)
#define rep0c(i, n) for (long long i = 0; i <= (long long)(n); i++)
#define rep1c(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define rep2c(i, n) for (long long i = 2; i <= (long long)(n); i++)
#define repc0(n, i) for (long long i = (long long)(n); i >= 0; i--)
#define repc1(n, i) for (long long i = (long long)(n); i >= 1; i--)
#define repc2(n, i) for (long long i = (long long)(n); i >= 2; i--)
#define REP(i, n, m) for (long long i = (long long)(n); i < (long long)(m); i++)

namespace solver {
  using namespace std;
  typedef long long ll;

  ll N, buffer[10];
  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  void init() {
    scanf("%lld", &N);
  }

  void rec(ll cur, ll maxv) {
    if(cur == N) {
      rep(i, N) cout << alphabet[buffer[i]];
      cout << endl;
      return;
    }
    rep0c(i, maxv) {
      buffer[cur] = i;
      rec(cur+1, max(maxv, i+1));
    }
  }

  void solve() {
    buffer[0] = 0;
    rec(1, 1);
  }
}

int main() {
  solver::init();
  solver::solve();
  return 0;
}