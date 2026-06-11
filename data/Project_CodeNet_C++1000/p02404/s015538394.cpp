#include<stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&a&&b)
	{
		int i,j;
		for(j=0;j<b;j++)
			{
				printf("#");
			}
		printf("\n");
		for(i=0;i<(a-2);i++)
		{
			printf("#");
			for(j=0;j<(b-2);j++)
			{
				printf(".");
			}
			printf("#\n");
		}
		for(j=0;j<b;j++)
			{
				printf("#");
			}
			
		printf("\n\n");
	}
	return 0;
 } 