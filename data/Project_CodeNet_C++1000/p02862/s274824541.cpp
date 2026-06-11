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

#define MAXN (1 << 12)
#define MOD ((ll)1e9 + 7)

ll mem[MAXN][MAXN];

ll f(int x, int y) {
	if ((x < 0) || (y < 0)) {
		return 0;
	}
	if ((x == 0) && (y == 0)) {
		return 1;
	}
	ll & ret = mem[x][y];
	if (ret != -1) {
		return ret;
	}
	ret = f(x - 2, y - 1) + f(x - 1, y - 2);
	ret %= MOD;
//	cerr << x << " " << y << " " << ret << endl;
	return ret;
}

int x, y;

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

ll inv(ll x) {
	return mypow(x, MOD - 2);
}

ll cnk(ll n, ll k) {
	if ((k < 0) || (k > n)) {
		return 0;
	}
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

ll solve(ll x, ll y) {
	if ((x + y) % 3) {
		return 0;
	}

	int n = (x + y) / 3;
	int k = (x - y + n) / 2;
	return cnk(n, k);

}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> x >> y;
	//cout << f(x, y) << endl;

/*	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (solve(i,j) != f(i,j)) {
				cout << i << " " << j << " " << solve(i,j) << " " << f(i,j) << endl;
				return 0;
			}
		}
	}*/
	cout << solve(x, y) << endl;

	return 0;
}
