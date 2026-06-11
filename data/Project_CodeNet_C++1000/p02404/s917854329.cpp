#include<stdio.h>
int main()
{
	int i,j,x,y;
	for(int t=1;;t++)
	{
		scanf("%d %d",&i,&j);
		if(i==0&&j==0) break;
		for(x=1;x<=i;x++)
		{
			for(y=1;y<=j;y++)
			{
				if((x>=2&&x<=i-1)&&(y>=2&&y<=j-1)) printf(".");
				else printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}