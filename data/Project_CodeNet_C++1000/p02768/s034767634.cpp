#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define INF (1LL<<60)
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


// 最大公約数
ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

// mod m におけるa の逆元
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

// 素因数分解
vector<pair<ll, ll>> prim;
void pf(ll n)
{
  ll s = sqrt(n);
  ll r = 0;
  for(ll i = 2; i <= s; i++) {
    if((n % i) == 0) {
      r = 0;
      do {
	r++;
	n = n / i;
      } while((n % i) == 0);
      prim.push_back({i, r});
    }
  }
  if(n > s) {
    prim.push_back({n, 1});
  }
}

ll f2n(ll n)
{
  if(n == 0) return 1;
  if(n == 1) return 2;
  ll ans = f2n(n / 2);
  ans = (ans * ans) % MOD;
  ans = (ans * ((n % 2) + 1)) % MOD;
  return ans;
}
  

ll ncr(ll n, ll r)
{
  ll a = 1, b = 1;
  rep1(i, r) {
    a = (a * (n - i + 1)) % MOD;
    b = (b * i) % MOD;
  }
  ll br = modinv(b, MOD);
  return (a * br) % MOD;
}


void solve()
{
  ll n, a, b; cin >> n >> a >> b;

  ll ttl = f2n(n) - 1;
  
  ll ans = 0;

  ans = (ttl - ncr(n, a)) % MOD;
  if(ans < 0) ans += MOD;
  ans = (ans - ncr(n, b)) % MOD;
  if(ans < 0) ans += MOD;
  
  
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
