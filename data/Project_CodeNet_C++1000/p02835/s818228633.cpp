#include <stdio.h>

int main ()
{	
	int r,s,t;
	
	scanf("%d %d %d", &r, &s, &t);
	
	if(r + s + t >= 22)
{
	printf("bust\n");
}	
	else
{
	printf("win\n");
}
	return 0;
}
	