#include<stdio.h>
int main()
{
	int H1,M1,H2,M2,K;
	scanf("%d %d %d %d %d",&H1,&M1,&H2,&M2,&K);
	M1 += H1 * 60;
	M2 += H2 * 60;
	int df = M2 - M1;
	printf("%d", df - K);
	return 0;
}