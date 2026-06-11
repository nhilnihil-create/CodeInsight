#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	
	long long res = 0;
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int ii = 1; ii <= k; ii++) {
				int gcd = __gcd(i, j);
				gcd = __gcd(gcd, ii);
				res += gcd;
			}
		}
	}
	
	printf("%lld\n", res);
}
