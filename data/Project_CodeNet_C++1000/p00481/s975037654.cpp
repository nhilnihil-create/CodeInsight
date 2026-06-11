#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int H,W,N;
vector<string> maze;
int bfs(int sx,int sy,int gx,int gy){
	int visited[1001][1001];
	int dist[1001][1001];
	memset(visited,0,sizeof(visited));
	memset(dist,0,sizeof(dist));
	
	queue<int> qx,qy;
	qx.push(sx);qy.push(sy);

	dist[sy][sx] = 0;
	visited[sy][sx] = 1;

	while(!qx.empty()){
		int x = qx.front();qx.pop();
		int y = qy.front();qy.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( nx < 0 || ny < 0 || ny >= H || nx >= W )continue;
			if( maze[ny][nx] != '.')continue;
			if( visited[ny][nx] )continue;

			qx.push(nx);
			qy.push(ny);
			dist[ny][nx] = dist[y][x] + 1;
			visited[ny][nx] = 1;

			if(ny == gy && nx == gx)return dist[ny][nx];
		}
	}
	return -1;
}

int main(void){
	
	cin >> H >> W >> N;

	maze = vector<string>(H);
	vector<int> gxs(N+1),gys(N+1);
	for(int i=0;i<H;i++){
		cin >> maze[i];
		for(int j=0;j<W;j++){
			char c = maze[i][j];
			if( c != '.' && c != 'X' ){
				if( c == 'S' ){
					gys[0] = i;
					gxs[0] = j;
				}else{
					gys[c - '0'] = i;
					gxs[c - '0'] = j;
				}
				maze[i][j] = '.';
			}
		}
	}

	int ret = 0;
	for(int i=0;i<N;i++){
		ret += bfs( gxs[i], gys[i], gxs[i+1], gys[i+1] );
	}
	cout << ret << endl;

	return 0;
}