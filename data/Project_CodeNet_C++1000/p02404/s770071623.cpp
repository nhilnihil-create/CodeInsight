#include<stdio.h>
int main()
{
	int H[300],W[300],i=0,j=0,k,l=0;
	for(l=0;l<300;l++)
	{
		scanf("%d %d",&H[l],&W[l]);
		if(H[l]==0&&W[l]==0)
			break;
	}
	for(k=0;k<l;k++)
	{
		for(i=1;i<=H[k];i++)
		{
			for(j=1;j<=W[k];j++)
			{
				if(i==1)
				{
					if(j==W[k])
						printf("#\n");
					else
						printf("#");
				}
				else if(j==1)
					printf("#");
				else if(j==W[k])
					printf("#\n");
				else if(i==H[k])
				{
					if(j==W[k])
						printf("#\n");
					else
						printf("#");
				}
				else
					printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}