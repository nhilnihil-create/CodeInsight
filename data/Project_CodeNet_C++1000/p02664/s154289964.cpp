#include <bits/stdc++.h>
using namespace std;

char a[1 << 20];
int dp[1 << 20][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a;
	int n = strlen(a);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (a[i] == 'P') {
				dp[i][1] = 0;
			}
			if (a[i] == 'D') {
				dp[i][0] = 1;
			}
			if (a[i] == '?') {
				dp[i][1] = 0;
				dp[i][0] = 1;
			}
			continue;
		}
		if (a[i] == 'P') {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		}
		if (a[i] == 'D') {
			dp[i][0] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
		}
		if (a[i] == '?') {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][0] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
		}
	}
	int cnt = 0;
	if (dp[n - 1][0] < dp[n - 1][1]) cnt = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == '?') {
			if (cnt == 0) a[i] = 'D';
			else a[i] = 'P';
		}
		if (a[i] == 'P') {
			if (dp[i][1] == dp[i - 1][0]) cnt = 0;
			else cnt = 1;
		}
		if (a[i] == 'D') {
			if (dp[i][0] == dp[i - 1][0] + 1) cnt = 0;
			else cnt = 1;
		}
		if (a[i] == '?') {
			if (cnt == 1) {
				if (dp[i][1] == dp[i - 1][0]) cnt = 0;
				else cnt = 1;
			} else {
				if (dp[i][0] == dp[i - 1][0] + 1) cnt = 0;
				else cnt = 1;
			}
		}
	}
	cout << a << endl;
	return 0;
}

