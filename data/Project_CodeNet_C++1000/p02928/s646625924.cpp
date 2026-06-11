#include <cstdio>
long long mod = 1000000007;
long long big(long long b, long long p){
	if (p == 1) return b;
	long long h = big(b, p / 2);
	long long res = (h * h) % mod;
	if (p % 2 == 1) res = (res * b) % mod;
	return res;
}
int main(){
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long a[n];
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	long long ans = 0;
	for (int i = 0; i < n; i++){
		long long e = 0, f = 0, g = 0, h = 0;
		for (int j = 0; j < n; j++){
			if (a[j] > a[i]){
				if (j < i) e++;
				f++;
			}else if (a[j] < a[i]){
				if (i < j) g++;
				h++;
			}
		}
		ans += (((((f + h) * k) % mod) * (k - 1) % mod) * big(2, mod - 2)) + ((e + g) * k) % mod;
		ans %= mod;
	}
	printf("%lld\n", (ans * big(2, mod - 2)) % mod);
}