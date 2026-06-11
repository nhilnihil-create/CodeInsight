#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll modpow(ll a, ll n, ll mod){
	
	ll res = 1;
	while(n > 0){
		if(n & 1) res = res * a % mod;
		a = a*a % mod;
		n /= 2;
	}
	return res;
}



ll inva(ll a, ll mod){
	
	ll inv_a = modpow(a, mod-2, mod);
	
	return inv_a;
}



ll modcon(ll n, ll k, ll mod){
	
	ll numer = 1;
	ll denom = 1;
	
	rep(i, k){
		numer = numer * (n-i) % mod;
		denom = denom * (k-i) % mod;
	}
	ll ans = numer * inva(denom, mod) % mod;
	
	return ans;
	
}

int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	ll n, a, b, m, ans; cin >> n >> a >> b;
	
	m = 1000000007;
	
	ll p2n = modpow(2, n, m);
	
	ll nCa = modcon(n, a, m);
	ll nCb = modcon(n, b, m);
	
	ans = 
	
	ans = p2n - ((nCa + nCb) % m + 1);
	
	cout << (ans+m) % m << endl;
	
	return 0;
}
