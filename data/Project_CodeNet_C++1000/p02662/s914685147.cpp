#include <bits/stdc++.h>
#define MAX (ll)(3e3 + 7)
#define INF (ll)(4e18)
#define MOD (ll)(998244353)

using namespace std;
using ll = long long;
using cd = complex<double>;

int dp[MAX][MAX];
int mult (int a, int b) {
	return (a * 1LL * b) % MOD;
}

int add (int a, int b) {
	return (a + b) % MOD;
}

int pw (int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mult  (r, a);
		}
		b >>= 1;
		a = mult (a, a);
	}	
	return r;
}

int main () {
	int n, s;
	cin >> n >> s;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	dp[0][0] = pw (2, n);
	int div = pw (2, MOD - 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i + 1][j] = add (dp[i + 1][j], dp[i][j]);
			if (ar[i] + j <= s) {
				dp[i + 1][ar[i] + j] = add (dp[i + 1][ar[i] + j], mult (dp[i][j], div))	;
			}
		}
	}
	cout << dp[n][s] << "\n";
}
		
