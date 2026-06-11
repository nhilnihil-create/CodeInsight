#include <stdio.h>

int main() {
	int a;
	long long int list[1000000],max = 1e18, result = 1, flag = 0, zero = 0;
	scanf("%lld", &a);
	for(int i = 0; i < a; i++){
		scanf("%lld", &list[i]);
		flag = (list[i] > max) ? 1 : flag;
		result *= list[i];
		(list[i]) ? max /= list[i] : zero = 1;
	}
	
	(zero) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", result)); 
	
	return 0;
}
