#include <stdio.h>

int main(void)
{
	int w[10000],h[10000];
	int i,j;
	int n;
	int howmany;
	
	for(n=0;n<10000;n++)
	{
		scanf("%d %d",&h[n],&w[n]);
		
		if(h[n] == 0 && w[n] == 0)
		{
			howmany = n;
			
			goto next;
		}
	}
	
	next:
	
	for(n=0;n<howmany;n++)
	{
		for(i=0;i<h[n];i++)
		{
			for(j=0;j<w[n];j++)
			{
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}