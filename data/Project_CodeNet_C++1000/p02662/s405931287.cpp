#include <iostream>
using namespace std;

const int64_t MOD = 998244353;
const int MAXS = 3010;
int64_t dp[MAXS];

int main() {
	int n, s;
	cin >> n >> s;
	dp[0] = 1;
	for (int i = 1; i <= s; ++i) {
		dp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = s; j >= 0; --j) {
			dp[j] = (2 * dp[j] + (j >= a ? dp[j - a] : 0)) % MOD;
		}
	}
	cout << dp[s] << endl;
	return 0;
}