#include <stdio.h>
int main()
{
	int N, R, v, z, x;
	scanf("%d %d", &N, &R);
	v = R + 100*(10-N);
	if ( N >= 10 ){
		printf("%d", R);
	}
	else {
		printf("%d", v);
	}
	return 0;
}