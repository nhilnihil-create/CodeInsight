#include <stdio.h>

int main(){
	int K, X, yen;
	scanf("%d %d", &K, &X);
	yen = K * 500;
	yen >= X ? printf("Yes") : printf("No");
	return 0;
}