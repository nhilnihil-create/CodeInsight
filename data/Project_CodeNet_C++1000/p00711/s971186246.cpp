#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
const int W = 20, H = 20;
char board[H][W];

int bfs(int x, int y, int w, int h){
	int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1}, c = 0;
	queue<P> q;
	q.push(make_pair(x, y));
	board[y][x] = '#';
	while(!q.empty()){
		P p = q.front();
		q.pop();
		++c;
		for(int i = 0;i < 4;++i){
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if(0 <= nx && nx < w && 0 <= ny && ny < h && board[ny][nx] == '.'){
				q.push(make_pair(nx, ny));
				board[ny][nx] = '#';
			}
		}
	}
	return c;
}

int main(){
	int w, h, x, y;
	while(cin >> w >> h, w){
		for(int i = 0;i < h;++i){
			for(int j = 0;j < w;++j){
				cin >> board[i][j];
				if(board[i][j] == '@'){
					x = j;
					y = i;
				}
			}
		}
		cout << bfs(x, y, w, h) << endl;
	}
	return 0;
}