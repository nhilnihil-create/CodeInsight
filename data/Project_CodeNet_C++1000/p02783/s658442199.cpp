#include <stdio.h>
int main()
{
	int x, y, z;
	scanf("%d %d", &x, &y);
	while (x>0)
	{
		x = x-y;
		z++;
	}
	printf("%d", z);
	return 0;
}