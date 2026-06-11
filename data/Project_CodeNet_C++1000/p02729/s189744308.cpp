#include <stdio.h>
int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	int sum = 0;
	for (int i = 1; i <= n-1; i++)
	{
		sum += i;
	}
	for (int i = 0; i <= m-1; i++)
	{
		sum += i;
	}
	printf("%d\n",sum);
	return 0;
}