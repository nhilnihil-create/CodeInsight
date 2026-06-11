#include <stdio.h>

int main()
{
	int c, dr; 
	scanf("%d %d", &c, &dr);
	
	if(c >=10)
{
	printf("%d" , dr);
}
    else
{
	printf("%d", dr+100*(10-c));
}
    return 0;
}



