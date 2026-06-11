
#include <cstdio>

using namespace std;

bool test(int n)
{
	while ((n & 1) == 0)
		n >>= 1;
	return n > 1;
}

int main()
{
	int N;
	scanf("%d", &N);
	if (test(N) == false)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d %d\n", 1, 2);
	printf("%d %d\n", 2, 3);
	printf("%d %d\n", 3, N + 1);
	printf("%d %d\n", N + 1, N + 2);
	printf("%d %d\n", N + 2, N + 3);
	for (int x = 4;x + 1 <= N;x += 2)
	{
		printf("%d %d\n", 1, x);
		printf("%d %d\n", x, x + 1);
		printf("%d %d\n", 1, (x + 1) + N);
		printf("%d %d\n", (x + 1) + N, x + N);
	}
	if ((N & 1) == 0)
	{
		for (int a = 2, b;a <= N;++a)
		{
			b = (N ^ 1 ^ a);
			if (1 <= b && b < N && a != b)
			{
				printf("%d %d\n", N, (a & 1) ? N + a : a), printf("%d %d\n", N + N, (b & 1) ? N + b : b);
				break;
			}
		}
	}
	return 0;
}