#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

ll repSquare(ll N, ll P, ll M) {
  if (P == 0)
    return 1;
  else if (P % 2 == 0) {
    ll half = repSquare(N, P / 2, M);
    return half * half % M;
  } else
    return N * repSquare(N, P - 1, M) % MOD;
}


void solve(ll n, ll a, ll b) {
  // 2^n - nCa - nCb
  // nCa mod = n! / (n-a)! a! = n! * ((n-a)!a!)^(MOD-2)
  
  ll all = repSquare(2, n, MOD) - 1;

  vector<ll> fact(b + 1);
  fact[1] = 1;
  FOR(i, 2, b + 1)
    fact[i] = fact[i - 1] * i % MOD;
  ll na(1), nb(1);
  REP(i, a)
    na = na * (n - i) % MOD;
  REP(i, b)
    nb = nb * (n - i) % MOD;

  ll nCa = na * repSquare(fact[a], MOD - 2, MOD) % MOD;
  ll nCb = nb * repSquare(fact[b], MOD - 2, MOD) % MOD;

  ll ans = (all - nCa) % MOD;
  ans = (ans - nCb) % MOD;
  if (ans < 0)
    ans += MOD;
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, a, b;
  cin >> n >> a >> b;

  solve(n, a, b);

  return 0;
}
