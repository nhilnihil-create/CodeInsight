#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	int g = A[N] - 1;
	for (int i = N - 1; i >= 0; --i) {
		g = g / 2 + A[i];
	}
	if (g >= 1) {
		cout << -1 << endl;
	}
	else {
		vector<long long> dp(N + 1);
		dp[0] = 1;
		for (int i = 1; i <= N; ++i) {
			dp[i] = min(dp[i - 1] * 2 - A[i], 1LL << 60);
		}
		long long s = 0, ans = 0;
		for (int i = N; i >= 0; --i) {
			s += A[i];
			ans += min(s, dp[i] + A[i]);
		}
		cout << ans << endl;
	}
	return 0;
}