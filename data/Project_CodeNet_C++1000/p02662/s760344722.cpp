#include <stdio.h>

const long long mod = 998244353;
const long long inv2 = (mod + 1) / 2;

int N, S; long long D[3030];

int main()
{
	scanf ("%d %d", &N, &S);
	
	D[0] = 1;
	for (int i = 0; i < N; i++) D[0] = D[0] * 2 % mod;
	
	while (N--){
		int x; scanf ("%d", &x);
		for (int i = S - x; i >= 0; i--){
			D[i + x] = (D[i + x] + D[i] * inv2) % mod;
		}
	}

	printf ("%lld\n", D[S]);

	return 0;
}
