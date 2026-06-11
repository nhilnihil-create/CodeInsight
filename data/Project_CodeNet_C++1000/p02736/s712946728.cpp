#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1e6 + 10;

int cnk(int n, int k) {
	while (k) {
		int dn = n & 1;
		int dk = k & 1;
		n >>= 1;
		k >>= 1;
		if (!dn && dk) {
			return 0;
		}
	}
	return 1;
}

int n;
int a[N];

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	bool one = false;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '1';
		one |= a[i] == 1;
	}
	if (!one) {
		for (int i = 0; i < n; ++i) {
			a[i] /= 2;
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i] & 1;
		res ^= cur * cnk(n - 1, i);
	}
	if (!one) {
		res *= 2;
	}
	cout << res << "\n";
	return 0;
}
