#include<stdio.h>
int main(void)
{
	int a,d;
	
	scanf("%d %d",&a,&d);
	
	printf("%d %d %lf",a/d,a%d,(double)a/d);
	
	return 0;
}