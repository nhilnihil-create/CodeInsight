#include <stdio.h>

int main()
{
	int K, X, tK;
	scanf("%d %d", &K, &X);
	tK = K * 500;
	if ( tK >= X ){
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}