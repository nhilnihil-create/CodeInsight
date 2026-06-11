#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	multiset<int> p, q, r, ans;
	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		p.insert(x);
	}
	for (int i = 0; i < b; i++) {
		int x;
		cin >> x;
		q.insert(x);
	}
	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;
		r.insert(x);
	}
	int i = 0;
	for (auto it = p.rbegin(); i < x; i++, it++) {
		ans.insert(*it);
	}
	i = 0;
	for (auto it = q.rbegin(); i < y; i++, it++) {
		ans.insert(*it);
	}
	while (c--) {
		auto rit = --r.end();
		auto ait = ans.begin();
		if (*rit > *ait) {
			ans.erase(ait);
			ans.insert(*rit);
			r.erase(rit);
		} else {
			break;
		}
	}
	long long sum = 0;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		sum += *it;
	}
	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}