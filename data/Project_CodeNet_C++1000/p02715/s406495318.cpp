#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
const ll mod = 1000000007;

ll modpow(ll a, ll n)
{
  ll res=1;
  while (n>0) {
    if (n&1) res = res*a % mod;
    a = a*a % mod;
    n >>= 1;
  }
  return res;
}

int main()
{
  ll N, K; cin >> N >> K;

  vector<ll> d(K+1);
  for (int i=K; i>=1; i--) {
    ll tmp = modpow(K/i, N);
    for (int j=2; j*i<=K; j++) {
      tmp = (tmp + mod - d[j*i]) % mod;
    }
    d[i] = tmp;
  }

  ll ans = 0;
  for (int i=1; i<=K; i++) {
    ans = (ans + i*d[i]) % mod;
  }
  cout << ans << endl;

  return 0;
}
