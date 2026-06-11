#include<stdio.h>
main()
{
	int a,b,c,x,y,z,i,j;
	for(int t=1;;t++)
	{
		scanf("%d %d",&i,&j);
		if(i==0&&j==0) break;
		for(x=1;x<=i;x++)
		{
			for(y=1;y<=j;y++)
			{
			   if((x%2==1&&y%2==0)||(x%2==0&&y%2==1))printf(".");
			   else printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}