#include <stdio.h>

int main()
{
	int x, y, z;
	scanf("%d%d", &x, &y);
	
	z = x*500;
	if(z>=y)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	
	return 0;
}