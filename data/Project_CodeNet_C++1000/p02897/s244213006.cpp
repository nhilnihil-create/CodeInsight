#include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
		printf("0.5\n");
	else 
		printf("%lf", (double)(n/2+1) / n);

	return 0;
}
