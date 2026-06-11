#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int W, H, ans;
string maze[20];

bool check(int x, int y){
	return x >= 0 && x < W && y >= 0 && y < H && maze[y][x] == '.';
}

void dfs(int x, int y){
	
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(check(nx, ny)){
			maze[ny][nx] = '#';
			ans++;
			dfs(nx, ny);
		}
	}
}

int main() {
	while(cin >> W >> H && (W || H)){
		for(int i = 0; i < H; ++i)
				cin >> maze[i];
		
		ans = 0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(maze[i][j] == '@'){
					dfs(j, i);
				}
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}