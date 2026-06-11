#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
using ll = long long;

ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; }
	return res;
}

int main() {
	ll a = 1000000007;
	ll N,K;
	cin >> N >> K;
	vector<ll> di(K+1);
	di[0] = 0;
	for (ll i = K; i > 0; --i) {
		//di[i] = pow(ll(K / i), N);
		di[i] = modpow(ll(K / i), N, a);
		for (ll j = 2; i * j <= K; ++j) {
			di[i] -= di[j * i];
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= K; ++i) {
		ans += di[i] * i % a;
		ans %= a;
	}
	cout << ans << endl;
	return 0;
}
