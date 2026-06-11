#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		++mp[a];
	}
	map<int, int> d;
	for(auto e : mp) {
		++d[e.second];
	}
	int l[n + 1] = {}, r[n + 1] = {};
	for(int k = 1; k <= n; ++k) {
		r[0] += d[k];
	}
	for(int x = 1; x <= n; ++x) {
		l[x] = l[x - 1] + x * d[x];
		r[x] = r[x - 1] - d[x];
	}
	int ans[n + 1] = {};
	for(int x = 1; x <= n; ++x) {
		int fx = (l[x] + x * r[x]) / x;
		ans[fx] = x;
	}
	for(int i = n - 1; i >= 1; --i) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for(int k = 1; k <= n; ++k) {
		cout << ans[k] << '\n';
	}
	return 0;
}