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

if(k==1){cout<<0<<endl;
return 0;}

ll a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
	a[i]--;
}
a[0]=0;
rep(i, n){
	a[i]=a[i-1]+a[i];
	a[i]%=k;
}


set <ll> ks;
for(int i=0;i<=n;i++){
ks.insert(a[i]);
}

ll m=ks.size();
ll ans=0;

map<ll, ll> mp;

ll num=-1;
for(auto itr=ks.begin(); itr!=ks.end();++itr){
ll s=*itr;
if(!mp.count(s)){
	++num;
	mp[s]=num;
}

}


queue<ll> que[m];
ll fin[n+1];

for(ll i=0;i<=n;i++){
	ll c=mp[a[i]];

que[c].push(i+k-1);
fin[i]=c;
ans+=que[c].size()-1;

if(i>=k-1){
	ll u=fin[i-k+1];
	que[u].pop();
}



}



cout<<ans<<endl;
return 0;






}



