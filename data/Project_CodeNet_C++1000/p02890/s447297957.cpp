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

int n;
int cnt[300010];
int cum[300010];

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[a]++;
	}
	sort(cnt + 1, cnt + n + 1);
	reverse(cnt + 1, cnt + n + 1);
	cum[1] = cnt[1];
	for (int i = 2; i <= n; i++)cum[i] = cum[i - 1] + cnt[i];
	int k = 1;
	for (int i = 1; i <= n; i++) {
		while (n - cum[k] < cnt[k] * (i - k) && k + 1 < i)k++;
		if (n - cum[k] < cnt[k] * (i - k))cout << (n - cum[k]) / (i - k) << endl;
		else cout << (n - cum[k - 1]) / (i - k + 1) << endl;
	}
}
