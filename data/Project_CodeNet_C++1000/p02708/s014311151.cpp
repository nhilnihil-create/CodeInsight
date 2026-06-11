#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	long long res = 0;
	
	for (int i = k; i <= n + 1; i++) {
		long long least = 1LL * i * (i - 1) / 2LL;
		long long most = 1LL * (n + 1) * n / 2LL - 1LL * (n + 1 - i) * (n - i) / 2LL;
		
		res = (res + (most - least + 1)) % MOD;
	}
	
	printf("%lld\n", res);
}
