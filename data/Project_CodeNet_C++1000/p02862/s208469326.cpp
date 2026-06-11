#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

//2^8 works in 2 sec but make sure to see the size
//2^7 works with 2 arrray of size of 2^7 but not three


int mod = 1e9 + 7;
ll p = 2e7 + 100;
//vector<ll> com(p + 1);
vector<ll> inv(p + 1);
vector<ll> mul(p + 1);

ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

ll C(ll n, ll k) {
	if (n < k || n < 0 || k < 0) return 0;
	ll maxm = max(k,n - k);
	ll minn = min(k,n - k);
	ll ans = 1;
	for (ll i = n; i > maxm; --i) {
		ans = (ans * i) % mod;
	}
	return (ans * mul[minn]) % mod;
}

int main() {	
	//com[0] = 1;
	//for (ll i = 1; i <= p; ++i) {
		//com[i] = (com[i - 1] * i) % mod;
	//} 
    inv[0] = 1;
    inv[1] = 1;
	for (ll i = 2; i <= p; ++i) {
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod; 
	}
	mul[0] = 1;
	for (int i = 1; i <= p; ++i) {
		mul[i] = (mul[i - 1] * inv[i]) % mod;
	}
	ll x, y;
	cin >> x >> y;
	if ((2 * x - y) % 3 != 0 || (2 * y - x) % 3 != 0) {
		cout << 0;
		return 0;
	} 
	ll a = (2 * x - y) / 3;
	ll b = (2 * y - x) / 3;
	cout << C(a + b, a);
}







