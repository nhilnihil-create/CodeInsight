#include<stdio.h>
main()
{
	int l,m,n;
	int a[200][200]={0},b[200][200]={0};
	long long int c[200][200]={0};
	scanf("%d %d %d",&n,&m,&l);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<l;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<m;k++)
		{
			for(int j=0;j<l;j++)
		   {
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		   }
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<l;j++)
		{
		    if(j!=0) printf(" ");
			printf("%lld",c[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}