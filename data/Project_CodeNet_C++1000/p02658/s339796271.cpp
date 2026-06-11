#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	long long int array[N], max = 1e18, x = 1, y = 0, z = 0;
	
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &array[i]);
		y = (array[i] > max) ? 1 : y;
		x = x*array[i];
		(array[i]) ? max = max/array[i] : z = 1;
	}
	(z) ? printf("0") : ((y) ? printf("-1") : printf("%lld\n", x));
	return 0;
}