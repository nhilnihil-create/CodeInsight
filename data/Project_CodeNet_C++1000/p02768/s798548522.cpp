#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

vector<long long> com;

ll modpow(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  if (n % 2 == 1) return (a * modpow(a, n - 1, mod)) % p;
  ll t = modpow(a, n / 2, mod);
  return (t * t) % mod;
}

ll inverse(ll a, ll p) {
  return modpow(a, p-2, p);
}

void comInit(long long n, long long k, long long p) {
  com.resize(k+1);
  com.at(0) = 1;
  long long tmp = 1;
  for (int i = 1; i <= k; i++) {
    tmp = ((tmp * (n-i+1) % p) * inverse(i, p)) % p;
    com.at(i) = tmp;
  }
}

long long MOD(long long val, long long p) {
  long long res = val % p;
  if (res < 0) res += p;
  return res;
}


int main(){
 ll n; cin >> n;
 int a,b; cin >> a >> b;
 ll ans=-1;
 ll p=modpow(2,n,mod); ans+=p;
 comInit(n, 200000, mod);
 ll d=MOD(com[a]+com[b],mod);

  cout  << MOD(ans-d,mod) << endl;
 }
