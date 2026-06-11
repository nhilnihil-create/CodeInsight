#include <bits/stdc++.h>
using namespace std;

long long f (int v, int i, int j) {
	return ((long long) v) * ((long long) abs(i - j));
}

signed main () {
	int n;
	cin >> n;
	vector < int > a(n);
	for (int &x: a) 
		cin >> x;
	vector < pair < int, int > > b(n);
	for (int i = 0; i < n; ++i)
		b[i] = make_pair(a[i], i);
	sort(b.rbegin(), b.rend());
	long long dp[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			dp[i][j] = -1e18;
	}
	for (int l = n - 1; l >= 0; --l) {
		for (int r = l; r < n; ++r) {
			int to_eat = l + (n - 1 - r);
			if (l == r)
				dp[l][r] = f(b[to_eat].first, b[to_eat].second, l);
			else 
				dp[l][r] = max(dp[l][r - 1] + f(b[to_eat].first, b[to_eat].second, r), dp[l + 1][r] + f(b[to_eat].first, b[to_eat].second, l));
		}
	}
	cout << dp[0][n - 1] << '\n';
}
