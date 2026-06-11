#include<stdio.h>
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	int K=0;
	int a;
	
	for (a=1;a<N;a++)
	{
		K += a;
	}
	
	int L=0;
	int b;
	
	for(b=1;b<M;b++)
	{
		L += b;
	}
	
	if (N+M>=2)
	{
		printf("%d\n", K+L);
	}
	else
	{
		printf("0\n");
	}
	
	return 0;
}