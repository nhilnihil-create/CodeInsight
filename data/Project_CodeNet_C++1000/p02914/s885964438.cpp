#include <bits/stdc++.h>

using namespace std;

#define li long long int

const int N = 1e5 + 3;

int n;
li a[N];
li basis[60];

void insertVector(li mask) {
	for (int i = 59; i >= 0; i--) {
		if (!(mask & (1ll << i))) continue;
		if (!basis[i]) {
			basis[i] = mask;
			return;
		}
		mask ^= basis[i];
	}
}

void solve() {
	cin >> n;
	li totXor = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		totXor ^= a[i];
	}
	li oddTimes = 0;
	for (int j = 0; j < 60; j++) {
		if (totXor & (1ll << j)) {
			for (int i = 1; i <= n; i++) {
				if (a[i] & (1ll << j)) {
					a[i] ^= (1ll << j);
				}
			}
			oddTimes |= (1ll << j);
		}
	}
	for (int i = 1; i <= n; i++) {
		insertVector(a[i]);
	}
	li maxXor = 0;
	for (int j = 59; j >= 0; j--) {
		if (!basis[j]) continue;
		if (maxXor & (1ll << j)) continue;
		maxXor ^= basis[j];
	}
	cout << oddTimes + 2 * maxXor;
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}