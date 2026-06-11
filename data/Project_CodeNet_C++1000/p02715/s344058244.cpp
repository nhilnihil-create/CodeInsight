#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = (int)1e9+7;

int modpow(int b, int x){
	if (x == 0) return 1;
	else if (x & 1){
		return (ll)b * modpow(b, x-1) % MOD;
	}
	else{
		int d = modpow(b, x/2);
		return (ll)d * d % MOD;
	}
}

int main(){
	int n, k; cin >> n >> k;

	vector<int> f(k + 1);	
	for (int i = 1; i <= k; ++i){
		f[i] = modpow(k/i, n);
	}

	for (int i = k; i >= 1; --i){
		for (int j = i * 2; j <= k; j+=i){
			f[i] = (f[i] - f[j] + MOD) % MOD;
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; ++i){
		ans = (ans + ((ll)f[i] * i) % MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}