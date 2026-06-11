#include <bits/stdc++.h>

using namespace std;

const int N = 2100, mod = 1e9+7;
int n, dp[N];

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%d", &n);

	dp[0] = 1;

	for (int i = 3; i <= n; i++){
		for (int j = 3; j < N; j++){
			if (i - j < 0)
				break;
			dp[i] = (dp[i] + dp[i - j])%mod;
		}
		//cout << i << " " << dp[i] << endl;
	}

	printf("%d\n", dp[n]);

	return 0;
}