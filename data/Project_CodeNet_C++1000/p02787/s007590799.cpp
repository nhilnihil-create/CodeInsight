#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int h, n; cin >> h >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	
	int dp[h + 1] = {};
	for (int j = 0; j < h; j++) {
		dp[j] = INT_MAX;
	}
	for (int i = 0; i < n; i++) {
		for (int j = h; j >= 0; j--) {
			if (dp[j] != INT_MAX)
				dp[max(0, j - a[i])] = min(dp[max(0, j - a[i])], dp[j] + b[i]);
		}
	}
	
	cout << dp[0] << "\n";
	
	return 0;
}