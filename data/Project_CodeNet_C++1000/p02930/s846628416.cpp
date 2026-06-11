#include<cstdio>

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int lb = 0;
	while(n>>lb) ++lb;
	
	for(int i=1; i<n; ++i)
	{
		for(int j=i+1; j<=n; ++j)
		{
			for(int k=0; k<lb; ++k)
			{
				if(((i>>k)&1) != ((j>>k)&1))
				{
					printf("%d ",k+1);
					break;
				}
			}
		}
		putchar('\n');
	}	
	return 0;
}