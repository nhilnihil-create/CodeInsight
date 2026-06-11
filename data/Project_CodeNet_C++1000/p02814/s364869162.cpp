#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;



ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a,b);
}

ll n, m;

int main() {
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
	}

	ll l = 1;
	for (int i = 0; i < n; i++) {
		l = lcm(a[i], l);
		if (l > m) {
			cout << "0" << endl;
			return 0;
		}
	}
	ll ans = (m / l + 1) / 2;
	int two = 1;
	while (!(l & 1)) {
		l >>= 1;
		two <<= 1;
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (a[i] % two) {
			ok = false;
		}
	}
	if (ok) {
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}
