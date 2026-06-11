#include <stdio.h>

int main(){
	// N Genap
	// M Ganjil
	int N,M,C,D;
	scanf("%d %d", &N, &M);
	C=(N-1)*N/2;
	D=(M-1)*M/2;
	printf("%d", C+D);
	return 0;
}