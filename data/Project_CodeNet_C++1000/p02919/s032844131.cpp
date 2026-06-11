#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n;
	cin >> n;
	vector < int > p(n);
	vector < pair < int, int > > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		a[i] = make_pair(p[i], i);
	}
	sort(a.rbegin(), a.rend());
	int64_t ans = 0;
	set < int > pos;
	for (int j = 0; j < n; ++j) {
		int i = a[j].second;
		int l1 = -1, l2 = -1, r1 = n, r2 = n;
		pos.insert(i);
		auto it = pos.find(i);
		if (it != prev(pos.end())) {
			r1 = *next(it);
			if (next(it) != prev(pos.end())) 
				r2 = *next(next(it));
		}
		if (it != pos.begin()) {
			l1 = *prev(it);
			if (prev(it) != pos.begin())
				l2 = *prev(prev(it));
		}
		ans += int64_t(p[i]) * (int64_t(r2 - r1) * int64_t(i - l1) + int64_t(l1 - l2) * int64_t(r1 - i));
	}
	cout << ans << '\n';
}
