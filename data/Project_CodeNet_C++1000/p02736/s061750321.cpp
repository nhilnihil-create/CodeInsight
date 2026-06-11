#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MAX 510000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);

using namespace std;
typedef long long int  ll;
typedef pair<ll, ll> P;

constexpr int MOD = 1000000007;
constexpr ll inf = 1LL << 60;

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
ll modinv(ll a, ll m) {
	if(m==0)return (ll)1;
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
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}
	return k;
}

//radP
ll rad(ll u, ll p){
ll cnt=0;
	while(u%p==0){
		u/=p;
		cnt++;
	}
	return cnt;
}


////////////////////////////////////////////////////////////////////

int bitCount(int u){
for(int i=0;i<=30;i++){
if(u & 1<<i)return 1;

}
return 0;

}

bool is_nCk_odd(int n, int k){
    return (n&k)==k;
}



int main(){
int n;
cin>>n;
int a[n+1];
string s;
cin>>s;
rep(i,n){
	a[i]=s[i-1]-'0';
	a[i]--;
}

if(n==2){
	cout<<abs(a[1]-a[2])<<endl;
	return 0;
}


int sum=0;
for(int i=0;i<=n-1;i++){
if(is_nCk_odd(n-1,i)){
	sum+=a[i+1];
}
}

sum=sum%2;
if(sum)cout<<1<<endl;
else{ 
for(int i=0;i<n;i++){
if(s[i]=='2'){
	cout<<0<<endl;
	return 0;}
}
rep(i,n){
	a[i]/=2;
}
int sum=0;
for(int i=0;i<=n-1;i++){
if(is_nCk_odd(n-1,i)){
	sum+=a[i+1];
}
}
sum=sum%2;
if(sum)cout<<2<<endl;
else cout<<0<<endl;

}




return 0;

}

