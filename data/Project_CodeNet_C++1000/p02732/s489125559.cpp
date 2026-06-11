#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int mod = 1e9 + 7;
ll p = 5e5 + 100;

int main() {	
	vector<ll> com(p + 1);
	vector<ll> inv(p + 1);
	vector<ll> mul(p + 1);
	com[0] = 1;
	for (ll i = 1; i <= p; ++i) {
		com[i] = (com[i - 1] * i) % mod;
	} 
    inv[0] = 1;
    inv[1] = 1;
	for (ll i = 2; i <= p; ++i) {
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod; 
	}
	mul[0] = 1;
	for (int i = 1; i <= p; ++i) {
		mul[i] = (mul[i - 1] * inv[i]) % mod;
	}
	
	int n;
	cin >> n;
	vector<ll> v(n);
	map<ll,ll> m;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		m[v[i]]++;
	}
	for (auto &x : m) {
		ans += (x.second * ( x.second - 1)) / 2;
	}
	for (int i = 0; i < n; ++i) {
		if (m[v[i]] > 1) { 
			ll py = ((m[v[i]] - 1) *(m[v[i]] - 2)) / 2;
			ll px = ((m[v[i]]) *(m[v[i]] - 1)) / 2;
			cout << ans - (px - py) << endl; 
		}else {
			cout << ans << endl;
		}
	}
}








