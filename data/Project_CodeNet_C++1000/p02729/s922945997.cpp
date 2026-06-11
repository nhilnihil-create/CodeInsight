#include<stdio.h>
int main()
{
	int N,M,total1,total2;
	scanf("%d %d", &N, &M);
	total1=(N-1)*(N)/2;
	total2=(M-1)*(M)/2;
	printf("%d", total1+total2);
return 0;
}