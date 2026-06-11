#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	for(a1=1; a1<N; a1++){a2 = a2+a1;}
	for(b1=1; b1<M; b1++){b2 = b2+b1;}
	(N+ M>= 2) ? printf("%d", a2 + b2) : printf("0");
	return 0;}
