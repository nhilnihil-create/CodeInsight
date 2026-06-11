#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const long long MOD = 1e9 + 7;

int a[N];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	long long ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (a[i] > a[j]) ans ++;
		}
	}
	ans = ans * k % MOD;
	for (int i = 1; i <= n; i++){
		long long t = 0;
		for (int j = 1; j <= n; j++){
			if (a[i] > a[j]) t++;
		}
		ans += (1LL * k * (k - 1) / 2) % MOD * t % MOD;
	}	
	printf("%lld", ans % MOD);
	return 0;
}