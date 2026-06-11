#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = (int) 1e9 + 5;
	for (int i = 0; i < n; ++i) {
		// start here, go right
		// end at a[i - 1]
		int cur = k - (a[i] - a[i - 1]);
		if (!i) cur = k - (k + a[i] - a.back());
		ans = min(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}