#include<stdio.h>
int main()
{
	int tensu[2];
	int a,b,c,d,i;

	for(i=0;i<2;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		tensu[i]=a+b+c+d;
	}

	if(tensu[0]<tensu[1])
	{
		printf("%d",tensu[1]);
	}
	else if(tensu[0]>tensu[1])
	{
		printf("%d",tensu[0]);
	}
	else
	{
		printf("%d\n",tensu[0]);
	}
	return 0;
}