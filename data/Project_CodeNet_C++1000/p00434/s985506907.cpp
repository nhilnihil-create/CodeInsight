#include<stdio.h>
int main()
{
	int i,j;
	int lasa[28];
	int value[31];

	for(i=1;i<=30;i++)
	{
		value[i]=i;
	}

	for(i=0;i<=28;i++)
	{
		scanf("%d\n",&lasa[i]);
	}

	for(i=0;i<29;i++)
	{
		for(j=1;j<31;j++)
		{
			if(lasa[i]==value[j])
			{
				value[j]=-1;
			}
		}
	}
	for(i=1;i<=30;i++)
	{
		if(value[i]>-1)
		{
			printf("%d\n",value[i]);
		}
	}
	return 0;
}