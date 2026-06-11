#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e3 + 69;
const ll MOD = 998244353;

int n, s;
int ar[N];
ll dp[N][N];

ll modpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {res = res * a % MOD;}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	// dp[0][0] = 1;
	dp[1][ar[1]] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= s; j++) {
			if(j < ar[i]) {
				dp[i][j] = 2 * dp[i - 1][j];
				dp[i][j] %= MOD;
			}
			if(j > ar[i]) {
				dp[i][j] = 2 * dp[i - 1][j] + dp[i - 1][j - ar[i]];
				dp[i][j] %= MOD;
			}
			if(j == ar[i]) {
				dp[i][j] = 2 * dp[i - 1][j] + modpow(2, i - 1);
				dp[i][j] %= MOD;
 			}
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= s; j++) {
	// 		cerr << i << " " << j << " " << dp[i][j] << "\n";
	// 	}
	// }

	cout << dp[n][s] << "\n";
	return 0;
}
