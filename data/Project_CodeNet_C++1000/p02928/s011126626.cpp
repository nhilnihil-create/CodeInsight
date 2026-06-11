#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


void solve()
{
  ll n, k; cin >> n >> k;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  ll ans = 0;
  ll i2 = modinv(2, MOD);
  ll kk2 = ((k - 1) * (( k * i2) % MOD)) % MOD;

  cerr << i2 << endl;
  REP(i, n) {
    ll c1 = 0, c2 = 0;
    REP(j, n) {
      if(a[i] > a[j]) {
	if(j < i) {
	  c1 ++;
	} else {
	  c2 ++;
	}
      }
    }
    
    ans += (c2 * k) % MOD;
    ans +=  ((c1 + c2) * kk2) % MOD ;
    ans %= MOD;
  }
  
  cout << ans % MOD << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
