#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

ll fac[2020];
ll finv[2020];
ll inv[2020];

void compre() {
  fac[0] = fac[1] = 1LL;
  finv[0] = finv[1] = 1LL;
  inv[1] = 1LL;
  for(ll i = 2LL; i<2020; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

long long modcom(long long n, long long k) {
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main() {
  ll n, k;
  cin >> n >> k;
  compre();
  for(ll i = 1LL; i<=k; i++) {
    ll a = modcom(k-1,i-1);
    ll b = modcom(n-k+1,i);
    cout << a * b % mod << endl;
  }
  return 0;
}