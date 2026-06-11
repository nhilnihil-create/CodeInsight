#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>




int main()
{
	int i,j,k;
	int n,m;
	int sum;
	int winner;
	int p;

	while(1)
	{
		scanf("%d %d %d",&n,&m,&p);
		if((n==0)&&(m==0)&&(p==0)){break;}
		else
		{
			sum=0;
			winner=0;
			for(i=0;i<n;i++)
			{
				int x;
				scanf("%d",&x);
				sum+=x;
				if((i+1)==m){winner=x;}
			}
		}
		if(winner==0){printf("0\n");}else{
			printf("%d\n",(sum*(100-p)/winner));}
	}
	return 0;
}
	