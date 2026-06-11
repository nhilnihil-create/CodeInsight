#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N;
pair<long long, int> A[1 << 18];
long long dp[2009][2009];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A, A + N);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 1; j <= N - i; j++) {
			long long cl = j, cr = j + i;
			dp[cl + 1][cr] = max(dp[cl + 1][cr], dp[cl][cr] + A[i].first * (A[i].second - cl));
			dp[cl][cr - 1] = max(dp[cl][cr - 1], dp[cl][cr] + A[i].first * (cr - A[i].second));
		}
	}

	long long ret = 0;
	for (int i = 1; i <= N + 1; i++) ret = max(ret, dp[i][i - 1]);
	cout << ret << endl;
	return 0;
}