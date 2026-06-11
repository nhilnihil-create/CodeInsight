#include <stdio.h>

int main(){
	
	int N, X, T;
	
	scanf("%d %d %d", &N, &X, &T);	
	N % X == 0 ? printf("%d", T * (N / X)) : printf("%d",   (T * (N / X)) + T);
	
	return 0;
}
