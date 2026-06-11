#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, D, K;

int main() {
	scanf("%lld %lld %lld", &X, &K, &D);
	X = abs(X);
	if (X / D > K) {
		printf("%lld\n", X - K * D);
		return 0;
	} else {
		ll cnt = X / D;
		if ((K - cnt) % 2 == 0) printf("%lld\n", X % D);
		else printf("%lld\n", (D - (X % D)));
	}
	return 0;
}