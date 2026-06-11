
#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[87];
long long dp[87];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	dp[1] = 1000;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j <= i - 1; j++) {
			long long V = dp[j] / A[j];
			long long W = dp[j] + (A[i] - A[j]) * V;
			dp[i] = max(dp[i], W);
		}
	}
	cout << dp[N] << endl;
	return 0;
}
