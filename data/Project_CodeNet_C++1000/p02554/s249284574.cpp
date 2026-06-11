#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int n;
	cin >> n;
	ll ans = pow_mod(10, n) - pow_mod(9, n) * 2 + pow_mod(8, n);
	ans %= mod;
	ans = (ans + mod) % mod;
	cout << ans << endl;
	return 0;
}