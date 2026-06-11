#include <stdio.h>

int main(void)
{
	
	int x,i;
	
	i=0;
	
	for(;;)
	{
		scanf("%d",&x);
		
		if(x==0)
		{break;}
		
		i++;
		
	printf("Case %d: %d\n",i,x);
	}
	return 0;
}
