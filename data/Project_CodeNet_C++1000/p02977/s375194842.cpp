#include <iostream>
#include <cstdio>
using namespace std;
int n;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	if(!(n & (n - 1))) {puts("No"); return 0;}
	puts("Yes"); puts("1 2"); puts("2 3");
	printf("%d %d\n", 3, n + 1); printf("%d %d\n", n + 1, n + 2); printf("%d %d\n", n + 2, n + 3);
	for(int i = 4; i + 1 <= n; i += 2)
	{
		int j = i + 1;
		printf("%d %d\n", 1, i);
		printf("%d %d\n", 1, j);
		printf("%d %d\n", i, j + n);
		printf("%d %d\n", j, i + n);
	}
	if(n % 2 == 0)
	{
		for(int i = 4; i <= n; i ++)
		{
			int j = n ^ i ^ 1;
			if(j != 3 && j < n)
			{
				printf("%d %d\n", i, n);
				printf("%d %d\n", j, 2 * n);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
