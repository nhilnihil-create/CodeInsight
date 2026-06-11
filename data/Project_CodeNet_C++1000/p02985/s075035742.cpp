#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;


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
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}
	return k;
}


////////////////////////////////////////////////////////////////////
ll ans;
ll k;
ll ruin=0;
vector<ll> vec[100005];

ll fin[100005];
ll al[100005];
ll kai[100005];


void bfs(ll u){
	ll cnt=0;
  for(ll i=0;i<vec[u].size();i++){
ll t=vec[u][i];
fin[t]++;
if(al[t]!=1) cnt++;
  }

if(k-fin[u]<cnt){ruin=1;}
  if(COM(k-fin[u],cnt)!=0)
ans*=COM(k-fin[u],cnt);
ans%=MOD;
ans*=kai[cnt];
ans%=MOD;
 for(ll i=0;i<vec[u].size();i++){
	 ll va=vec[u][i];
if(al[va]==0){
	al[va]=1;
bfs(va);
  }

}
}





int main() {
ll n;
cin>>n>>k;
ans=k;
COMinit();

kai[0]=1;
kai[1]=1;
for(ll i=2;i<=100001;i++){
	kai[i]=kai[i-1]*i;
	kai[i]%=MOD;
}


for(int i=1;i<=n-1;i++){
ll a,b;
cin>>a>>b;
vec[a].push_back(b);
vec[b].push_back(a);
}

rep(i, n){
	fin[i]=1;
	al[i]=0;
}


ll st=0;
for(int i=1;i<=n;i++){
	if(vec[i].size()==1){
st=i;
break;
	}
}

al[st]=1;

bfs(st);

if(ruin){cout<<0<<endl;
return 0;}

cout<<ans<<endl;
return 0;




}


