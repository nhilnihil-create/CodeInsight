#include <bits/stdc++.h>

using namespace std;

long long mypow(long long x, long long y) {
	long long tot = 1LL;
	while (y) {
		if (y & 1) tot = tot * x;
		y >>= 1;
		x = x * x;
	}
	return tot;
}

int main() {
	long long n;
	scanf("%lld", &n);
	
	long long res = 0;
	
	// p = 0
	int v = sqrt(n - 1);
	if (n - 1 >= 2) res++;
	for (int i = 2; i <= v; i++) {
		if ((n - 1) % i == 0) {
			res++;
			if ((n - 1) / i != i && (n - 1) / i >= 2) res++;
		}
	}
	
	// p = 1 to 39
	for (int i = 1; i <= 39; i++) {
		long long lim = (long long)pow(n, 1.0 / i);
		if (mypow(lim + 1, i) <= n) lim++;
		if (mypow(lim, i) == n) res++;
		
		lim = (long long)pow(n, 1.0 / (i + 1));
		
		for (int j = 2; j <= lim; j++) {
			if (n - mypow(j, i) > 0 && (n - mypow(j, i)) % mypow(j, i + 1) == 0) res++;
		}
	}
	
	printf("%lld\n", res);
}
