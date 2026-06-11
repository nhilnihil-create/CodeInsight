#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 20;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> dp(n - 1, vector<ll>(MAX + 1));
	dp[0][a[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= MAX; j++) {
			if (0 <= j + a[i] && j + a[i] <= MAX) {
				dp[i][j + a[i]] += dp[i - 1][j];
			}
			if (0 <= j - a[i] && j - a[i] <= MAX) {
				dp[i][j - a[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 2][a[n - 1]] << endl;
	return 0;
}

