#include <cstdio>
#include <set>
#include <iostream>

const int STEP_NUM = 4;
const int STEP[STEP_NUM][STEP_NUM] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int MAXSIZE = 1000;
char field[MAXSIZE + 1][MAXSIZE + 1];

const int MAXN = 10;
int locationsX[MAXN];
int locationsY[MAXN];
 
int H, W, N;

int get_shortest_distance(int current_HP)
{
	int sx = locationsX[current_HP-1];
	int sy = locationsY[current_HP-1];
	int ex = locationsX[current_HP];
	int ey = locationsY[current_HP];

	bool is_visit[MAXSIZE + 1][MAXSIZE + 1];
	for(int i=0;i<MAXSIZE;i++)
		for(int j=0;j<MAXSIZE;j++)
			is_visit[i][j]=false;
	std::set<std::pair<int,int>> frontier;
	frontier.insert(std::pair<int,int>{sx,sy});
	for(int step=0;step<100000000;step++)
	{
		for(auto p:frontier)
		{
			if(p.first==ex && p.second==ey)	return step;
			is_visit[p.first][p.second] = true;
		}
		std::set<std::pair<int,int>> next_frontier;
		for(auto p:frontier)
		{
			for(int i=0;i<STEP_NUM;i++)
			{
				int nx = p.first+STEP[i][0];
				int ny = p.second+STEP[i][1];
				if(nx<0 || H<=nx) continue;
				if(ny<0 || W<=ny) continue;
				if(field[nx][ny]=='X') continue;
				if(is_visit[nx][ny]) continue;
				next_frontier.insert(std::pair<int,int>{nx,ny});
			}
		}
		frontier = next_frontier;
	}
	return -1;
}

int solve()
{
	int total_step = 0;
	for(int i=1;i<N+1;i++)
		total_step += get_shortest_distance(i);
	return total_step;
}

int main()
{
	scanf("%d %d %d", &H, &W, &N);
	for(int i=0; i<H; i++)
		scanf("%s", field[i]);
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
		{
			int HP=-1;
			if(field[i][j]=='S')	HP=0;
			if(field[i][j]=='1')	HP=1;
			if(field[i][j]=='2')	HP=2;
			if(field[i][j]=='3')	HP=3;
			if(field[i][j]=='4')	HP=4;
			if(field[i][j]=='5')	HP=5;
			if(field[i][j]=='6')	HP=6;
			if(field[i][j]=='7')	HP=7;
			if(field[i][j]=='8')	HP=8;
			if(field[i][j]=='9')	HP=9;
			if(HP!=-1)
			{
				locationsX[HP]=i;
				locationsY[HP]=j;
			}
		}
	printf("%d\n", solve());
	return 0;
}