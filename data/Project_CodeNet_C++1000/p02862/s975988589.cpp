#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
const lint mod = 1e9+7, N = 1e6+100;
lint x, y, fat[N];

lint fpow(lint b, lint e){
	if (b == 0)
		return 0;
	if (e == 0)
		return 1;
	if (e % 2 == 0){
		lint p = (fpow(b, e/2))%mod;
		return (p * p)%mod;
	} else {
		return ((b%mod) * fpow(b, e-1))%mod;
	}
}

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%lld %lld", &x, &y);

	if ((x + y)%3 != 0){
		printf("0\n");
		return 0;
	}

	lint a = (2*y - x) / 3;
	lint b = (2*x - y) / 3;

	//cout << a << "  " << b << endl;

	if (a < 0 || b < 0){
		printf("0\n");
		return 0;
	}

	fat[0] = fat[1] = 1;

	for (lint i = 2; i < N; i++){
		fat[i] = (i * fat[i - 1])%mod;
	}

	lint ans = fat[(a+b)] * fpow(fat[b], mod-2) % mod * fpow(fat[a], mod-2) % mod;

	printf("%lld\n", ans);

	return 0;
}