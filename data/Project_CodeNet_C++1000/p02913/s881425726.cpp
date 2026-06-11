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
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//べき//
ll squ(ll n, ll p, ll m){
	if(p==0) return 1;
	if(p%2==0){
		ll t=squ(n, p/2, m);
		return t*t%m;
	}
	return n*squ(n,p-1,m);
	
}


//逆元mod(mを法とするaの逆元)//
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

// テーブルを作る前処理
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

// 二項係数計算
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nが大

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


int main() {
ll n;
string s;
cin>>n;
cin>>s;

ll large=n/2;
ll small=1;
ll ans=0;

for(int u=1;u<=17;u++){
	ll mid;
	if(u<=16) {mid=(large+small)/2;}
else {mid=ans+1;}
ll ac=0;
vector<pair<string,int>> vec{};
for(int k=0;k<=n-mid;k++){
	string r=s.substr(k,mid);
vec.push_back(make_pair(r,k));
}
sort(ALL(vec));
string nowstr=vec[0].first;
ll nowv=vec[0].second;
for(int i=0;i<n-mid;i++){
	
	if(vec[i].first==vec[i+1].first && abs(vec[i].second-vec[i+1].second)>=mid){
		ans=max(ans,mid);
		ac=1;
		break;
	}
	if(vec[i].first!=vec[i+1].first){ nowstr=vec[i+1].first; nowv=vec[i+1].second;}
if(vec[i].first==vec[i+1].first){
	if(abs(vec[i+1].second-nowv)>=mid){
		ans=max(ans,mid);
		ac=1;
		break;
	}
}
}


if(ac){small=mid;}
else {large=mid;}
if(mid==1 && ac==0){
	cout<<0<<endl;
	return 0;
}



}
cout<<ans<<endl;
return 0;




}


