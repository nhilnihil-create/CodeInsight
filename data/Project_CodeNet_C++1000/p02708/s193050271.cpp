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
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	vector<ll> sum_prefix(n + 2);
	vector<ll> sum_suffix(n + 2);
	for (ll i = 1; i <= n; ++i) {
		sum_prefix[i] = (i + sum_prefix[i - 1]) % mod;
	}
	for (ll i = n; i >= 0; --i) {
		sum_suffix[i] = (i + sum_suffix[i + 1]) % mod;
	}
	//sum_suffix[0] = sum_suffix[1];
	//sum_suffix[n] = sum_prefix[n + 1];
	//sum_suffix[0] = sum_suffix[1];
	//sum_suffix[0] = sum_suffix[1];
	//for (int i = 0; i <= n; ++i) {
		//cout << sum_prefix[i] <<  " " << sum_suffix[i] << "  ";
	//}
	//cout << endl;
	for (int i = k; i <= n + 1; ++i) {
		ll pp = (sum_suffix[n - i + 1]  + mod - sum_prefix[i - 1]) + 1;
		//cout << pp << endl;
		ans = (ans + pp) % mod;
	}
	cout << ans;
}
//1  6 







