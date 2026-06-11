#include <bits/stdc++.h>

using namespace std;


#define PI 3.14159265
#define int long long

const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;

int fak[MAXN], inv[MAXN];


int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}


int C(int k, int n){
	return fak[n] * inv[k] * inv[n - k];
}

void calc(){
	fak[0] = fak[1] = 1;
	for(int i = 2; i < MAXN; i++){
		fak[i] = fak[i - 1] * i;
		fak[i] %= MOD;
	}

	for(int i = 0; i < MAXN; i++){
		inv[i] = binpow(fak[i], MOD - 2);
	}
}


main(){


	calc();

	int n, k; cin >> n >> k;

	vector <int> dp(n + 2), sum(n + 1);

	for(int i = 0; i <= n; i++) sum[i] = i;
	for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for(int i = 0; i <= n; i++) sum[i] %= MOD;

	dp[n + 1] = 1;

	for(int i = n; i > 0; i--){
		dp[i] = (sum[n] - sum[n - i] - sum[i - 1] + 1 + 2 * MOD);
		dp[i] %= MOD;
 	}

	// for(int i = n; i > 0; i--){
	// 	cout << dp[i] << ' ';
	// }
	// cout << endl;

	for(int i = n; i > 0; i--){
		dp[i] += dp[i + 1];
		dp[i] %= MOD;
	}

	cout << dp[k] << endl;


	
	
	return 0;
}