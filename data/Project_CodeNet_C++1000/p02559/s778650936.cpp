#include <bits/stdc++.h>
#define int long long
using namespace std;

struct fenwick {
	vector<int> t;
	int n;

	fenwick(int _n) {
		n = _n;
		t.assign(n, 0);
	}
	int sum(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) {
			res += t[r];
		}
		return res;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void update(int pos, int delta) {
		for(; pos < n; pos = (pos | (pos + 1))) {
			t[pos] += delta;
		}
	}
};

main() {
	int n, q;
	cin >> n >> q;
	fenwick fenw(n);
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		fenw.update(i, val);
	}
	while(q--) {
		int id, l, r;
		cin >> id >> l >> r;
		if(!id) {
			fenw.update(l, r);
		} else {
			cout << fenw.sum(l, r - 1) << endl;
		}
	}
}