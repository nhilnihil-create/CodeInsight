#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

ll k, q, d[5010], n, x, m;

signed main() {
	cin >> k >> q;
	for (int i = 0; i < k; i++)cin >> d[i];
	for (int i = 0; i < q; i++) {
		cin >> n >> x >> m;
		ll cnt = x % m, ans = 0;
		for (int j = 0; j < k; j++) {
			ll p = 0;
			ll s = d[j] % m;
			if (s == 0)s = m;
			if (j < (n - 1) % k)p = (n - 1) / k + 1;
			else p = (n - 1) / k;
			cnt += s * p;
		}
		ans += cnt / m;
		cout << n - 1 - ans << endl;
	}
}