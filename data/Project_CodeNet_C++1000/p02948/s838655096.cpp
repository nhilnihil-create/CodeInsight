#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, m;
	cin >> n >> m;
	vector < pair < int, int > > oneoff(n);
	for (int i = 0; i < n; ++i) 
		cin >> oneoff[i].second >> oneoff[i].first;
	sort(oneoff.rbegin(), oneoff.rend());
	set < int > days;
	for (int i = 0; i <= m; ++i)
		days.insert(i);
	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		int a = oneoff[i].second, b = oneoff[i].first;
		if (a <= m) {
			auto j = days.upper_bound(m - a);
			if (!days.empty() && j != days.begin()) {
				days.erase(prev(j));
				ans += b;
			}
		}
	}
	cout << ans << '\n';
}
