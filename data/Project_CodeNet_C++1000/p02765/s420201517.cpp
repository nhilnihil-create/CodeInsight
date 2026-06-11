#include<stdio.h>
int main()
{
	int K, R;
	int inner;
	scanf("%d %d", &K, &R);
	inner = 100 * (10-K);
	
	if(K<10)
	{
		printf("%d\n", inner+R);
	}
	else if(K>=10)
	{
		printf("%d\n", R);
	}
	return 0;
}