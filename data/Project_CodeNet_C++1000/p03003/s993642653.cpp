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
	int n, m;
	cin >> n >> m;
	vector<int> s(n);
	vector<int> t(m);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {


			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD_CONST;
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = (dp[i][j] + 1) % MOD_CONST;
			}
			else {
				dp[i][j] = (dp[i][j] - dp[i - 1][j - 1] + MOD_CONST) % MOD_CONST;

			}
		}
	}
	cout << (dp[n][m] + 1 + MOD_CONST) % MOD_CONST << endl;
}


