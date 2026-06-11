#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	int count = 1;
	int sum = 0;
	rep(i, n)
	{
		int temp;
		scanf("%d", &temp);
		sum += temp;
		if (sum <= x)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}