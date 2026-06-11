#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const ll mod = 1000000007;

ll powmod(ll a, ll n, ll m){
	ll p = 1;
	while(n > 0){
		if(n & 1) p = p * a % m;
		a = a * a % m;
		n >>= 1; 
	}
	return p;
}

ll modinv(ll a, ll m){
	return powmod(a, m - 2, m);
}

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	ll x, y; cin >> x >> y;
	if((x + y) % 3 != 0) cout << 0 << endl;
	else{
		ll n, m;
		n = (2*x-y)/3; m = (2*y-x)/3;
		if(n < 0 || m < 0){
			cout << 0 << endl;
			return 0;
		}
		ll a = 1, b = 1;
		for(ll i = 1; i <= n; i++){
			b *= modinv(i, mod);
			b %= mod;
		}
		for(ll i = n + m; i > m; i--){
			a *= i;
			a %= mod;
		}
		cout << a * b % mod << endl;
	}
} 