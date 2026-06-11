/*0ms,1360KB*/

#include<cstdio>
#include<cstring>

char grid[105][105], flag;

bool dfs(int i, int j)
{
	if (!grid[i][j] || grid[i][j] != flag) return false;
	grid[i][j] = 0;
	dfs(i - 1, j); dfs(i + 1, j); dfs(i, j - 1); dfs(i, j + 1);
	return true;
}

int main()
{
	int x, y, i, j, cnt;
	while (scanf("%d%d\n", &y, &x), x)
	{
		memset(grid, 0, sizeof(grid));
		cnt = 0;
		for (i = 1; i <= y; ++i)
			gets(grid[i] + 1);
		for (i = 1; i <= y; ++i)
			for (j = 1; j <= x; ++j)
			{
				flag = grid[i][j];
				if (dfs(i, j)) ++cnt;
			}
		printf("%d\n", cnt);
	}
	return 0;
}