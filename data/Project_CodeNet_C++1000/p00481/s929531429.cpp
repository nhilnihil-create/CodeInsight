#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<LL, LL> P;
struct edge { LL to, cost; };

int H, W, N;
std::string field[1123];
int Sx, Sy, x[11], y[11], ans;

int d[1123][1123];
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
void bfs(LL sx, LL sy, LL gx, LL gy)
{
	std::queue<P>que;
	memset(d, -1, sizeof(d));
	que.push({ sx,sy });
	d[sx][sy] = 0;
	while (que.size() > 0)
	{
		auto pos = que.front(); que.pop();
		if (pos.first == gx && pos.second == gy) { break; }
		rep(i, 4)
		{
			auto toX = pos.first + dx[i], toY = pos.second + dy[i];
			if (0 <= toX && toX < H && 0 <= toY && toY < W)
			{
				if (field[toX][toY] != 'X' && d[toX][toY] == -1)
				{
					que.push({ toX,toY });
					d[toX][toY] = d[pos.first][pos.second] + 1;
				}
			}
		}
	}
}

int main()
{
	in >> H >> W >> N;
	rep(i, H) { in >> field[i]; }

	rep(i, H)
	{
		rep(j, W)
		{
			if (field[i][j] == 'X') { continue; }
			if (field[i][j] == 'S') { Sx = i; Sy = j; }
			else if (field[i][j] != '.') { x[field[i][j] - '0'] = i; y[field[i][j] - '0'] = j; }
		}
	}
	x[0] = Sx; y[0] = Sy;
	rep(i, N)
	{
		bfs(x[i], y[i], x[i + 1], y[i + 1]);
		ans += d[x[i + 1]][y[i + 1]];
	}
	out << ans << std::endl;
	return 0;
}