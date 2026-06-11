#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;

const int MOD = (int)(1e+9) + 7;
int N;
vector<vll> dp;

int main(void) {
	cin >> N;
	dp.resize(2, vll(2, vl(N + 1, 0)));
	dp[0][0][1] = 8;
	dp[0][1][1] = 1;
	dp[1][0][1] = 1;
	dp[1][1][1] = 0;
	for (int k = 2; k <= N; ++k) {
		dp[0][0][k] = (dp[0][0][k - 1] * 8) % MOD;
		dp[0][1][k] = (dp[0][0][k - 1] + ((dp[0][1][k - 1] * 9) % MOD)) % MOD;
		dp[1][0][k] = (dp[0][0][k - 1] + ((dp[1][0][k - 1] * 9) % MOD)) % MOD;
		dp[1][1][k] = (dp[0][1][k - 1] + dp[1][0][k - 1]  + ((dp[1][1][k - 1] * 10) % MOD)) % MOD;
	}
	cout << dp[1][1][N] << '\n';
	return 0;
}
