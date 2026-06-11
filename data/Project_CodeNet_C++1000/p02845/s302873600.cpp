#include<bits/stdc++.h>

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

namespace solver {
  using namespace std;
  typedef long long ll;

  ll N, A[100010];
  map<ll, ll> cur;

  void init() {
    scanf("%lld", &N);
    rep(i, N) scanf("%lld", A+i);
    cur[-1] = 3;
  }

  void solve() {
    ll ans = 1;
    rep(i, N) {
      ans = (ans * cur[A[i]-1]) % MOD_1_000_000_007;
      cur[A[i]-1]--;
      cur[A[i]]++;
    }
    printf("%lld\n", ans);
  }
}

int main() {
  solver::init();
  solver::solve();
  return 0;
}