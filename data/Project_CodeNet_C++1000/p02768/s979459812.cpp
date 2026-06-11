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

typedef long double ld;
typedef long long ll;

using namespace std;

#define MOD 1000000007

ll mypow(ll n, ll k) {
	ll ret = 1;
	ll cur = n;
	while (k) {
		if (k & 1) {
			ret *= cur;
			ret %= MOD;
		}
		cur *= cur;
		cur %= MOD;
		k >>= 1;
	}
	return ret;
}

ll inv(ll n) {
	return mypow(n, MOD - 2);
}

ll cnk(ll n, ll k) {
	ll ret = 1;
	for (ll i = n - k + 1; i <= n; i++) {
		ret *= i;
		ret %= MOD;
	}
	for (ll i = 1; i <= k; i++) {
		ret *= inv(i);
		ret %= MOD;
	}
	return ret;
}

ll sub(ll a, ll b) {
	return (a + MOD - b) % MOD;
}

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
/*
	for (int i = 1; i <= n; i++) {
		cout << inv(i) << endl << endl;
		return 0;
	}
	cout << endl;
	cout << mypow(2,n) << endl;
	cout << cnk(n,a) << endl;
	cout << cnk(n, b) << endl;

*/
	cout << sub(sub(sub(mypow(2,n), 1), cnk(n, a)), cnk(n, b)) << endl;

	return 0;
}
