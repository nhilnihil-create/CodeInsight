#include<stdio.h>
int main()
{
	int N;
	int M;
	int total;
	scanf("%d %d",&N,&M);
	N=--N*(N+1)/2;
	M=--M*(M+1)/2;
	total= N + M;
	printf("%d",total);
	
	return 0;
}