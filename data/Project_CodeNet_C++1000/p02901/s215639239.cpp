#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 100000000

using namespace std;
using ll = long long;
int dp[1001][4097];

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M + 1);
	vector<int> C(M + 1);

	rep(i, M) {
		int a, b;
		cin >> a >> b;
		A[i + 1] = a;
		
		int n = 0;
		rep(j, b) {
			int c;
			cin >> c;

			n = n + (1 << --c);
		}
		C[i + 1] = n;
	}

	rep(j, 1 << N + 1) {
		dp[0][j] = INF;
	}

	dp[0][0] = 0;

	for (int i = 1; i < M+1; i++) {
		rep(j, 1 << N) {
			dp[i][j] = dp[i - 1][j];
		}
		rep(j, 1 << N) {
			dp[i][j | C[i]] = min(dp[i][j | C[i]], dp[i-1][j] + A[i]);
		}
	}

	ll ans = dp[M][(1 << N) - 1];
	if (ans == INF) ans = -1;

	cout << ans << endl;

	return 0;
}