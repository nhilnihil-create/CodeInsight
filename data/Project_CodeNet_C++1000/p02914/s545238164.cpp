#include <iostream>
#include <string>
#include <queue>

typedef long long int ll;

using namespace std;

int N;

ll a[100002];

ll min(ll a, ll b) {
	return (a < b) ? a : b;
}
ll max(ll a, ll b) {
	return (a > b) ? a : b;
}

ll solve() {
	int i, j, ki;
	ll res = 0;

	ll allxor = 0;
	for (i = 0; i < N; i++) {
		allxor ^= a[i];
	}
	for (i = 0; i < N; i++) {
		a[i] &= ~allxor;
	}

	ll rank = 0;
	for (i = 59; i >= 0; i--) {
		for (j = rank; j < N; j++) {
			if (a[j] & (1LL << i)) break;
		}
		if (j == N) {
			continue;
		}

		if (j > rank) a[rank] ^= a[j];
		for (j = rank + 1; j < N; j++) {
			a[j] = min(a[j], a[j] ^ a[rank]);
		}

		rank++;
	}
	ll x = 0;
	for (i = 0; i < N; i++) {
		x = max(x, x ^ a[i]);
	}

	res = (x * 2) + allxor;

	return res;
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	cout << solve();

	return 0;
}