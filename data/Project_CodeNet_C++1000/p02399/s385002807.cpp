#include<stdio.h>
int main(void)
{
	int a,b;
	double f;

	scanf("%d %d",&a,&b);

	f=1.0*a/b;

	printf("%d %d %.5f\n",a/b,a%b,f);

	return 0;
}