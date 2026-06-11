#include<stdio.h>
int main()
{
	int i,j,x,y;
	while(1)
	{
		scanf("%d %d",&i,&j);
		if(i==0&&j==0) break;
		for(x=1;x<=i;x++)
		{
			for(y=1;y<=j;y++)
			{
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	 return 0;
	
}