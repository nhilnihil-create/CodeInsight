#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

void chmax(Int& a, Int b) { if (a < b) { a = b; } }

int main() {
	int N;
	cin >> N;
	vector<Int> a(N + 1);
	for (int i = 1; i <= N; ++i) { cin >> a[i]; }

	vector<Int> dp(N + 1, 0);
	dp[0] = 1000;
	for (int i = 1; i <= N; ++i) {
		chmax(dp[i], dp[i - 1]);
		for (int j = 1; j < i; ++j) {
			Int val = dp[j] / a[j] * a[i] + dp[j] % a[j];
			chmax(dp[i], val);
		}
	}
	cout << dp[N] << endl;

	return 0;
}
