#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = 1e9+7;

ll mod(ll x) {
	x = x % MOD;

	if (x < 0) {
		x += MOD;
	}

	return x;
}

int main() {
	int n;

	cin >> n;

	vector <ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll ans = 0;

	for (int j = 0; j < 60; j++) {
		ll ones = 0;
		ll zeros = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] & (1LL << j)) {
				ones++;
			} else {
				zeros++;
			}
		}

		ans = ans + mod(mod(1LL << j) * mod(ones * zeros));
		ans = mod(ans);
	}

	cout << ans << "\n";

	return 0;
}