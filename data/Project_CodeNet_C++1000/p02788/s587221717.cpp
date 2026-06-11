#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int r (int a, int b) {
	return (a + b - 1) / b;
}

signed main () {
	int n, d, a;
	cin >> n >> d >> a;
	vector < pair < int, int > > gays(n);
	for (pair < int, int > &p: gays) 
		cin >> p.first >> p.second;
	sort(gays.begin(), gays.end());
	long long ans = 0;
	queue < pair < int, int > > pipes;
	long long dmg = 0;
	for (int i = 0; i < n; ++i) {
		int x = gays[i].first, h = gays[i].second;
		if (dmg) {
			h -= dmg;
			while (!pipes.empty() && pipes.front().first == i) {
				dmg -= pipes.front().second;
				pipes.pop();
			}
			if (h > 0) {
				int j = prev(lower_bound(gays.begin(), gays.end(), make_pair(x + 2 * d, inf))) - gays.begin();
				if (i == j)
					ans += r(h, a);
				else {
					ans += r(h, a);
					dmg += a * r(h, a);
					pipes.push(make_pair(j, a * r(h, a)));
				}
			}
		}
		else {
			int j = prev(lower_bound(gays.begin(), gays.end(), make_pair(x + 2 * d, inf))) - gays.begin();
			if (i == j)
				ans += r(h, a);
			else {
				ans += r(h, a);
				dmg += a * r(h, a);
				pipes.push(make_pair(j, a * r(h, a)));
			}
		}
	}
	cout << ans << '\n';
}
