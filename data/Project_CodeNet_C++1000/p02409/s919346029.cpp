#include<stdio.h>
int main()
{
	int a[4][3][10]={0},b,f,r,v,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&b,&f,&r,&v);
		a[b-1][f-1][r-1]=a[b-1][f-1][r-1]+v;
	}
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<3;y++)
		{
			for(int z=0;z<10;z++)
			{
				printf(" %d",a[x][y][z]);
			}
			printf("\n");
		}
		if(x!=3) printf("####################\n");
	}
	return 0;
}