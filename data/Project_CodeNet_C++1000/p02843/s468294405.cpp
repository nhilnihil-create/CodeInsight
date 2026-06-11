#include<stdio.h>
int main()
{
	int a,i,n;
	scanf("%d", &n);
	a=n/100;
		if(n>=a*100 && n<=105*a)
		{
			printf("1\n");
			return 0;
		}
	printf("0\n");
	return 0;
}