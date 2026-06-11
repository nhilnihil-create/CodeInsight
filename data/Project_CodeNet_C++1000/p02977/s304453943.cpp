#include <iostream>
#include <cstdio>
#define MN 101000

int main()
{
	int n; scanf("%d", &n);
	int m = 1; while(m * 2 <= n) m <<= 1;
	if(n == m) return 0 * puts("No");
	int k = n ^ m;
	if(n & 1) k = 0;
	int s = k / 4 * 4; 
	puts("Yes");
	if(!s)
	{
		puts("1 2"); puts("2 3"); printf("3 %d\n", n + 1); printf("%d %d\n", n + 1, n + 2); printf("%d %d\n", n + 2, n + 3);
	}
	else
	{
		for(int i = 0; i < 3; i++) 
		{
			printf("%d %d\n", s + i, s + i + 1);
			printf("%d %d\n", s + i + n, s + i + 1 + n);
		}
		printf("%d %d\n", s + 3, s + n);
	}
	for(int i = 0; i < s; i += 2) 
	{
		if(i)
		{
			printf("%d %d\n", i, i + 1);
			printf("%d %d\n", i + n, i + 1 + n);
		}
		printf("%d %d\n", k == 0 ? 1 : k, i == 0 ? 1 : i);
		printf("%d %d\n", k + 1, i + 1 + n);
	}
	for(int i = s + 4; i < n; i += 2) 
	{
		if(i)
		{
			printf("%d %d\n", i, i + 1);
			printf("%d %d\n", i + n, i + 1 + n);
		}
		printf("%d %d\n", k == 0 ? 1 : k, i == 0 ? 1 : i);
		printf("%d %d\n", k + 1, i + 1 + n);
	}
	if(!(n & 1))
	{
		printf("%d %d\n", n, m);
		printf("%d %d\n", k, n + n);
	}
}