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

#define INF (1LL << 60)

#define MAXN (1 << 20)

ll a[MAXN], f[MAXN];

ll n, k;

bool ok(ll val) {
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ll t = val - (val % f[i]);	
		ll x = max(0LL, a[i] - (t / f[i]));
		ret += x;
	}
	return (ret <= k);
}

int main() {
	cin >> n >> k;
	ll sum = 0;
	for (int i= 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	sort(f, f + n, greater<ll>());
	if (k >= sum) {
		cout << 0 << endl;
		return 0;
	}

	ll l = 0, r = INF;

	while (r - l > 1) {
		ll med = (l + r) / 2;
		if (ok(med)) {
			r = med;
		} else {
			l = med;
		}
	}
	cout << r << endl;
	return 0;
}
