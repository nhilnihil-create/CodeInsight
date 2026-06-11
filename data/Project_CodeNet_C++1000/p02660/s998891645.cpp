#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
ll n;
vector<ll> p;

int main() {
	cin >> n;
	for (ll i=2; i*i<=n; i++) {
		if (n % i == 0) {
			ll e = 0;
			while (n % i == 0) {
				e++;
				n /= i;
			}
			p.push_back(e);
		}
	}
	if (n != 1)
		p.push_back(1);
	ll ans = 0;
	for (ll x : p) {
		// cout << x << "\n";
		ll i = 1;
		while (x >= i) {
			x -= i;
			ans++;
			i++;
		}
	}
	cout << ans << "\n";
}