#include<stdio.h>
int main()
{
	int a,b,d=0;
	scanf("%d %d",&a,&b);
	printf("%d %d %lf\n",a/b,a%b,(double)a/(double)b);
	return 0;
}