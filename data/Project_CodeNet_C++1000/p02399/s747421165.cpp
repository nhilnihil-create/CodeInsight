#include <cstdio>

int main()
{
	int x ,y;
	scanf("%d %d", &x, &y);
	printf("%d %d %f\n", x/y, x%y, (double)x/y);
	return 0;
}