#include<stdio.h>
int main(void)
{
	int a,b,x,y;
	double z;
	scanf("%d %d",&a,&b);
	x=a/b;
	y=a%b;
	z=(double)a/b;
	printf("%d %d %lf\n",x,y,z);
	return 0;
}
