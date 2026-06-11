#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int f(int x) {
	int ret = 0;
	while (x % 2 == 0) {
		x /= 2;
		ret++;
	}
	return ret;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i] /= 2;
	int t = f(a[0]);
	rep(i, n) {
		if (f(a[i]) != t) {
			cout << 0 << endl;
			return 0;
		}
		a[i] >>= t;
	}
	m >>= t;
	ll l = 1;
	rep(i, n) {
		l = lcm(l, a[i]);
		if (l > m) {
			cout << 0 << endl;
			return 0;
		}
	}
	m /= l;
	cout << (m + 1) / 2 << endl;
	return 0;
}