#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;


int main() {
	string l;
	cin >> l;

	int n = l.length();
	vector<vector<ll>> dp(2, vector<ll>(n + 1));

	vector<ll> pow2(n + 1);
	vector<ll> pow3(n + 1);

	pow2[0] = pow3[0] = 1;
	for (int i = 1; i <= n; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD_CONST;
		pow3[i] = (pow3[i - 1] * 3) % MOD_CONST;
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[0][i - 1];
		dp[1][i] = dp[1][i - 1];

		if (l[i - 1] == '1') {
			dp[0][i]++;
			dp[1][i] = (dp[1][i] + (pow2[dp[0][i - 1]] * pow3[n - i]) % MOD_CONST) % MOD_CONST;
		}

	}

	ll ans = (dp[1][n] + (pow2[dp[0][n]]) % MOD_CONST) % MOD_CONST;
	cout << ans << endl;

}


