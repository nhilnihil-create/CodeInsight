#include<stdio.h>
int main(void)
{
	int a,b;
	double c,d;
	scanf("%d %d",&a,&b);
	printf("%d\n",a/b);
	printf("%d\n",a%b);
	c=a;
	d=b;
	printf("%.8lf\n",c/d);
	return 0;
}