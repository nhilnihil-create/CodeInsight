#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 1e9
using namespace std;
using P = pair<int, int>;

int dx[] = {1, 0};
int dy[] = {0, 1};
char maze[110][110];
int h, w;
vector<vector<int>> dp(110, vector<int>(110, INF));
int dfs(int x, int y, char color)
{
	int cnt, tmp;
	if (dp[x][y] != INF) return dp[x][y];
	cnt = INF;
	rep(i, 2)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > h + 1 || ny > w + 1) continue;
		if ((nx == 0 && ny > 1) || (nx > 1 && ny == 0)) continue;
		if ((nx == h + 1 && ny < w) || (nx < h && ny == w + 1)) continue;
		tmp = dfs(nx, ny, maze[nx][ny]);
		if (color == '#' && maze[nx][ny] == '.') tmp++;
		cnt = min(tmp, cnt); 
	}
	if (cnt == INF) cnt = 0;
	return dp[x][y] = cnt;
}

signed main(void)
{
	cin >> h >> w;

	for (int i = 1; i <= h; i++) 
		for (int j = 1; j <= w; j++)
			cin >> maze[i][j];
	rep(i, h + 2) maze[i][0] = maze[i][w + 1] = '.';
	rep(i, w + 2) maze[0][i] = maze[h + 1][i] = '.';
	dfs(0, 0, maze[0][0]);
	/*rep(i, h + 2)
	{
		rep(j, w + 2)
		{
			if (dp[i][j] == INF)
				cout << "INF  ";
			else
			cout << dp[i][j] << "    "; 
		}
		cout << endl;
	}*/
	cout << dp[0][0] << endl;
	return 0;
}
