#include<stdio.h>
int main ()
{
	int i,l;
	int value[31]={0};

	for(i=0;i<28;i++)
	{
		scanf("%d",&l);
		value[l]=1;
	}
	for(i=1;i<=30;i++)
	{
		if(value[i]!=1)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}