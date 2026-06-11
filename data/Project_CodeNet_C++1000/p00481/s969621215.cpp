#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define INF -1

typedef pair<int, int> P;

char mas[1000][1000];
int h, w, n, px, py, cnt = 0, life = 1;
int d[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int bfs(){

  queue<P> que;

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      d[i][j] = INF;
    }
  }
  
  que.push(P(px, py));
  d[py][px] = 0;

  while(!que.empty()){
    P p = que.front(); que.pop();
    int x = p.first;
    int y = p.second;
    
    /*
    for(int i = 0; i < h; ++i){
      for(int j = 0; j < w; ++j){
	if(i == y && j == x)cout << 'M';
	else cout << mas[i][j];
      }
      cout << endl;
    }
    cout << endl;
    */

    //if(mas[y][x] != 'S' && mas[y][x] != '.'){
    if(life == (mas[y][x] - '0')){  
      ++life;
      px = x;
      py = y;
      mas[y][x] = '.';
      return d[y][x];
    }

    for(int i = 0; i < 4; ++i){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(0 <= nx && nx < w && 0 <= ny && ny < h && mas[ny][nx] != 'X' && d[ny][nx] == INF){
	que.push(P(nx, ny));
	d[ny][nx] = d[y][x] + 1;
      }
    }
  }
  return 0;
}

int main(){

  cin >> h >> w >> n;

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cin >> mas[i][j];
      if(mas[i][j] == 'S'){
	px = j;
	py = i;
      }
    }
  }

  for(int i = 0; i < 9; ++i){
    cnt += bfs();
  }
  
  cout << cnt << endl;

  return 0;
}