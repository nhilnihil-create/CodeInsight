#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool uin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T>
inline bool uax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int nax = 2010;

long long dp[nax][nax];
long long A[nax];
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<long long> order(N);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](const long long& i, const long long& j) { return A[i] > A[j]; });

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j + i < N; ++j) {
			int pos = order[i + j];
			uax(dp[i + 1][j], dp[i][j] + A[pos] * abs(pos - i));
			uax(dp[i][j + 1], dp[i][j] + A[pos] * abs(pos - (N - 1 - j)));
		}
	}

	long long ans = 0;
	for (int i = 0; i < N; ++i) uax(ans, dp[i][N - i]);
	cout << ans << '\n';
}