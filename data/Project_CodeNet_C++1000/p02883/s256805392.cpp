#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define Rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//lcm//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//a^n mod p//
ll modpow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}


//inversemod//
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

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];

// 
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//LARGE n

ll com(ll n,ll m){
    if(n<m || n<=0 ||m<0){
		return 0;
	}
	if( m==0 || n==m){
		return 1;
	}
	
	ll k=1;
	for(ll i=1;i<=m;i++){
       k*=(n-i+1); 
	
	   k/=i;
	
	}

	return k;
}


////////////////////////////////////////////////////////////////////



int main() {
ll n,k;
cin>>n>>k;
ll cap[n+1];
ll f[n+1];
rep(i,n){
	cin>>cap[i];
}
rep(i, n){
	cin>>f[i];
}

ll ans=10000000000000;
sort(f+1,f+n+1);
sort(cap+1,cap+n+1,greater<ll>());

ll large=10000000000000;
ll small=0;

for(int y=1;y<=60;y++){
ll mid=(large+small)/2;
ll cost=0;
for(ll l=1;l<=n;l++){
	cost+=max((ll)0,cap[l]-mid/f[l]);
}
if(cost<=k){ans=min(ans,mid);
large=mid;
}
else{small=mid;}



}

cout<<ans<<endl;
return 0;




}


