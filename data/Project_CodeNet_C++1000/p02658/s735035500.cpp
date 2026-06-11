#include <stdio.h>

int main() {
	int n;
	
	scanf("%d", &n);
	
	long long int in[n], max = 1e18, drop = 1, point = 0, oh = 0;
	
	for(int J = 0; J < n; J++) {
		scanf("%lld", &in[J]);
		point = (in[J] > max) ? 1 : point;
		drop *= in[J];
		(in[J]) ? max /= in[J] : oh = 1;
		
	}
	
	(oh) ? puts("0") : ((point) ? puts("-1") : printf("%lld", drop));
		
	return 0;
}