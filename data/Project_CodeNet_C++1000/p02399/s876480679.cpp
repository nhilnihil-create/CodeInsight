#include<stdio.h>
int main(void)
{
	double f,e,x;
	int a,b,d,r;
	
	scanf("%d %d",&a,&b);
	
	d=a/b;
	r=a%b;
	
	e=a;
	x=b;
	
	f=e/x;
	
	printf("%d %d %1f",d,r,f);
	return 0;
}