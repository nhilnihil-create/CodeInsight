#include <bits/stdc++.h>
using namespace std;

int64_t req (int64_t to, int n, vector < int > &a, vector < int > &f) {
	int64_t res = 0;
	for (int i = 0; i < n; ++i) {
		if (int64_t(a[i]) * int64_t(f[i]) > to) 
			res += int64_t(a[i]) - (to / int64_t(f[i]));
	}
	return res;
}

signed main () {
	int n;
	int64_t k;
	cin >> n >> k;
	vector < int > a(n), f(n);
	for (int i = 0; i < n; ++i)	
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());
	int64_t l = 0, r = 1e12;
	while (r - l > 1) {
		int64_t m = (l + r) / 2;
		if (req(m, n, a, f) <= k)
			r = m;
		else 
			l = m;
	}
	if (req(l, n, a, f) <= k)
		cout << l << '\n';
	else
		cout << r << '\n';
}
