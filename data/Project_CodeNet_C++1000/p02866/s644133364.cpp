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

#define MOD (998244353)

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

#define MAXN (1 << 20)

int a[MAXN], d[MAXN];
int n;


int main() {
	cin >> n;
	int mmax = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
		d[i] = t;
		mmax = max(mmax, t);
	}
	if ((a[0] != 1) || (d[0] != 0)) {
		cout << 0 << endl;
		return 0;
	}
	ll ret = 1;
	for (int i = 0; i < mmax; i++) {
//		cerr << a[i] << " " << a[i + 1] << endl;
		ret *= mypow(a[i], a[i + 1]);
		ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}
