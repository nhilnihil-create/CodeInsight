#include<stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		double c=a*1.0/b;
		printf("%d %d %.5lf\n",a/b,a%b,c);
	}
	return 0;
 } 