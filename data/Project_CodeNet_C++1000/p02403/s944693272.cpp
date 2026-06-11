#include <stdio.h>
 
int main(void)
{
    int i, n;

	for(;;)
	{
		scanf("%d%d",&i,&n);

    if(i !=0&&n !=0)
	{
	for(int x=0;x<i;x++)
	{
	for(int y=0;y<n;y++)
	{
		printf("#");
	}
		printf("\n");
	}
	    printf("\n");
	}
	else{
		break;
	}
	}
    return 0;
}