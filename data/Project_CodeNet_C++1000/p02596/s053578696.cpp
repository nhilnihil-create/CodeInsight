#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
	ll k;
	cin >> k;
	int i, j;
	vector<ll> a(k);

	a[0] = 7 % k;
	for (i = 1; i < k; i++) {
		a[i] = (a[i - 1] * 10 + 7) % k;
	}
	for (i = 0; i < k; i++) {
		if (a[i] == 0) {
			cout << i + 1;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}