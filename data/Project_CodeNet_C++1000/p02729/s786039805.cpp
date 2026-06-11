#include <stdio.h>
int main () {
	int N,M,sum1,sum2;
	scanf("%d %d", &N,&M);
	sum1=(N-1)*(N)/2 ;
	sum2=(M-1)*(M)/2 ;
	printf("%d", sum1+sum2);
}