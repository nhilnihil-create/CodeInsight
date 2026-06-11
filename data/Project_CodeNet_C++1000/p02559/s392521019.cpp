#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct bit {
	int n;
	vector<ll> d;
	bit(int num) : n(num), d(num, 0) {}
	void add(int p, int x) {
		p++;
		while (p <= n) {
			d[p - 1] += x;
			p += p & -p;
		}
		return;
	}
	ll sum(int l, int r) {
		return s(r) - s(l);
	}
	ll s(int r) {
		ll res = 0;
		while (r > 0) {
			res += d[r - 1];
			r -= r & -r;
		}
		return res;
	}
};
int main() {
	int n, q;
	cin >> n >> q;
	bit bt(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		bt.add(i, a);
	}
	for (int i = 0; i < q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0)
			bt.add(x, y);
		else
			cout << bt.sum(x, y) << endl;
	}
	return 0;
}