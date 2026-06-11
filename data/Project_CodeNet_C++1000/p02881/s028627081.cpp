#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll ans = 1e15;
	for (ll i = 1; i * i <= n; ++i) {
		if (!(n % i)) {
			ans = min(ans, n / i + i - 2);
		}
	}
	cout << ans << endl;
}
