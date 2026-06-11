#include <bits/stdc++.h>

using namespace std;

int W, H;
char room[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int sx, sy;

int dfs(int x, int y)
{
  room[y][x] = '#';
  int cnt = 1;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i], ny = y + dy[i];
    if(0 <= nx && nx < W && 0 <= ny && ny < H && room[ny][nx] != '#'){
      cnt += dfs(nx, ny);
    }
  }
  return cnt;
}

int main()
{
  while(cin >> W >> H, W || H){
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	cin >> room[i][j];
	if(room[i][j] == '@') sx = j, sy = i;
      }
    }
    cout << dfs(sx, sy) << endl;
  }
  return 0;
}