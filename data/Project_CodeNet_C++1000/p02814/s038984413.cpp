#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>
#include<functional>
#include<queue>

using ll = long long;

using namespace std;

ll mod = 1000000007;

ll n_pow(ll a, ll n) {
	if (n == 0)return 1;
	ll t = n_pow(a, n / 2);
	t *= t;
	t %= mod;
	if (n % 2 == 1)t *= a;
	return t % mod;
}

const int INF = 1001001001;
//const ll INF = 1e18;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

ll cal_gcd(ll a, ll b) {
	ll m = max(a, b);
	ll n = min(a, b);
	while (m%n != 0) {
		ll b = m % n;
		m = n;
		n = b;
	}
	return n;
}

int main() {
	int n;
	ll m;
	cin >> n >> m;
	vector<ll>a(n);
	bool ok = true;
	int f2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
	}
	ll lcd = a[0];
	ll foo = a[0];
	while (foo % 2 == 0) {
		foo /= 2;
		f2++;
	}
	for (int i = 1; i < n; i++) {
		if (ok) {
			int tmp = 0;
			ll foo = a[i];
			while (foo % 2 == 0) {
				foo /= 2;
				tmp++;
			}
			if (f2 != tmp)ok = false;
		}
		ll gcd = cal_gcd(lcd, a[i]);
		lcd = lcd * a[i] / gcd;
		if (lcd > m)break;
	}
	ll ans = m / lcd;
	if (ans % 2 == 1)ans += 1;
	ans /= 2;
	if (ok) {
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}