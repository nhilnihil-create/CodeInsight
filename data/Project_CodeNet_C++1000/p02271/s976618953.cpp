#include <cstdio>
int a[20];
int n;
int dfs(int m,int sum,int i)
{
	if (i >= n)return 0;
	if (sum + a[i] == m)return 1;

	return dfs(m, sum + a[i], i + 1) + dfs(m, sum, i + 1);
}

void A()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int m;
		scanf("%d", &m);
		if (dfs(m,0, 0)> 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

int main()
{
	A();
	return 0;
}