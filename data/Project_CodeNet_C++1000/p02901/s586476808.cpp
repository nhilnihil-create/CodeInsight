#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)(2e+9);
int N, M;
vector<int> A;
vector<int> B;
vector<int> dp;

void input_init(void) {
	cin >> N >> M;
	A.resize(M);
	B.resize(M, 0);
	for (int j = 0; j < M; ++j) {
		int b;
		cin >> A[j] >> b;
		for (int i = 0; i < b; ++i) {
			int c;
			cin >> c;
			B[j] += (1 << (c - 1));
		}
	}
}

void solve(void) {
	dp.resize(1 << N, INF);
	dp[0] = 0;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < M; ++j) {
			int m = i | B[j];
			dp[m] = min(dp[i] + A[j], dp[m]);
		}
	}
}

int main(void) {
	input_init();
	solve();
	int ans = dp[(1 << N) - 1];
	if (ans == INF)
		ans = -1;
	cout << ans << '\n';
	return 0;
}
