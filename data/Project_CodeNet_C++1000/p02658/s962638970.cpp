#include <stdio.h>

int main () {
	int N;
	scanf("%d", &N);
	long long int ar[N], maximum =1e18, pRod = 1, flag = 0;
	long long int zero = 0;
	
	for (int i = 0 ; i < N; i++) {
		scanf("%lld", &ar[i]);
		flag = (ar[i] > maximum) ? 1 : flag;
		pRod *= ar[i];
		(ar[i]) ? maximum /= ar[i] : zero = 1;
	}
	(zero) ? puts("0") : (flag) ? puts("-1") : printf ("%lld\n", pRod);
	return 0;
}