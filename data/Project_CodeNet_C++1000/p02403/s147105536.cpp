#include<stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&a&&b)
	{
		int i,j;
		for( i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				printf("#");
			}
			printf("\n");
		}
		
			printf("\n");
	}
	return 0;
 } 