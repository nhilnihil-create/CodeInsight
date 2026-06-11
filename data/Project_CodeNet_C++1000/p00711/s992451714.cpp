#include <cstdio>
#include <cstring>
using namespace std;

int W, H;
char map[20][20];
int cnt;
int angle[][2] = {
	{-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

void dfs(int x, int y)
{
	if (map[x][y] == '#' || x < 0 || y < 0 || x >= W || y >= H){
		return;
	}
	cnt++;
	map[x][y] = '#';
	
	for (int i = 0; i < 4; i++){
		dfs(x + angle[i][0], y + angle[i][1]);
	}
}

int main()
{
	int num;
	
	while (scanf("%d %d", &W, &H), W + H){
		int x;
		int y;
		memset(map, 0, sizeof(map));
		
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				scanf(" %c", &map[j][i]);
				if (map[j][i] == '@'){
					x = j;
					y = i;
					map[j][i] = '.';
				}
			}
		}
		
		cnt = 0;
		dfs(x, y);
		
		printf("%d\n", cnt);
	}
	
	return 0;
}