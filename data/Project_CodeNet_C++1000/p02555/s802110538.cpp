#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

const int MOD = (int)(1e+9) + 7;
int S, N;
vector<vl> dp;

int main(void) {
	cin >> S;
	N = S / 3;
	dp.resize(N + 1, vl(S + 1, (ll)0));
	for (int j = 3; j <= S; ++j)
		dp[1][j] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 3 * i; j <= S; ++j) {
			for (int k = 3; k <= S; ++k) {
				int sum = j + k;
				if (sum > S)
					break;
				dp[i + 1][sum] += dp[i][j];
				dp[i + 1][sum] %= MOD;
			}
		}
	}
	ll ans = (ll)0;
	for (int i = 1; i <= N; ++i) {
		ans += dp[i][S];
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
