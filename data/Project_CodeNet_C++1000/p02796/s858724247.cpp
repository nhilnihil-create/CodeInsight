#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100500][2], dp[100500][2];
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> tmp(n);
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i - 1].first >> tmp[i - 1].second;
	}
	sort(begin(tmp), end(tmp));
	for (int i = 1; i <= n; i++) {
		a[i][0] = tmp[i - 1].first;
		a[i][1] = tmp[i - 1].second;
	}
	dp[0][1] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		if (a[i][0] - a[i][1] >= dp[i - 1][1]) {
			dp[i][1] = a[i][0] + a[i][1];
			dp[i][0] += 1;
		}
		else {
			if (dp[i - 1][1] > a[i][0] + a[i][1]) {
				dp[i][1] = a[i][0] + a[i][1];
			}
			else {
				dp[i][1] = dp[i - 1][1];
			}
		}
	}
	cout << dp[n][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}