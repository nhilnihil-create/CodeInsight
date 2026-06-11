#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
	int h,w,n;
	int sx,sy;
	int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
	string map[1001];
	int d[1001][1001];
	int x = 0;
	cin >> h >> w >> n;
	for(int i=0;i < h;i++)
	{
		cin >> map[i];
	}
	for(int i=0;i < h;i++)
	{
		for(int j=0;j < w;j++)
		{
			d[j][i] = -1;
			if(map[i][j] == 'S')
			{
				sx = j;
				sy = i;
			}
		}
	}
	d[sx][sy] = 0;
	for(int i=0;i<9;i++)
	{
		queue< pair<int, int> > que;
		for(int j=0;j < h;j++)
		{
			for(int k=0;k < w;k++)
			{
				d[k][j] = -1;
			}
		}
		d[sx][sy] = 0;
		que.push(make_pair(sx,sy));
		while(que.size())
		{
			pair<int, int> p = que.front();
			que.pop();
			if((map[p.second][p.first] - '0') == (i+1))
			{
				sx = p.first;
				sy = p.second;
				x+=d[sx][sy];
				break;
			}
			for(int j=0;j < 4;j++)
			{
				int nx = p.first + dx[j];
				int ny = p.second + dy[j];
				if(0 <= nx && nx < w && 0 <= ny && ny < h && map[ny][nx] != 'X' && d[nx][ny] == -1)
				{
					que.push(make_pair(nx,ny));
					d[nx][ny] = d[p.first][p.second] + 1;
				}
			}
		}
	}
	cout << x << endl;
}