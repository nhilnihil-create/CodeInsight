#include <bits/stdc++.h>
using namespace std;

int n, m, sum;
int main()
{
	cin >> n >> m >> sum;
	if (sum < 1000000000)
	{
		for (int i = 1; i <= n; ++i)
			printf("%d ", i<=m?sum:1000000000);
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			printf("%d ", i<=m?sum:sum-1);
	}
	printf("\n");
}