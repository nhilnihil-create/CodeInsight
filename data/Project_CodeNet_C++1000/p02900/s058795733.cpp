#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void solve() {
	ll a, b;
	cin >> a >> b;
	ll g = gcd(a, b);
	int cnt = 0;
	for (ll i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			ll t = g / i;
			if (isPrime(i)) cnt++;
			if (isPrime(t) && t != i) cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}