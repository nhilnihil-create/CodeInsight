#include <iostream>

using namespace std;

int w, h;
int c[50][50];
char dx[] = {-1,-1,-1,0,1,1,1,0};
char dy[] = {-1,0,1,1,1,0,-1,-1};

void dfs(int x, int y){
	c[x][y] = 0;
	for(int i=0;i<8;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx<0||h<=nx||ny<0||w<=ny||!c[nx][ny]) continue;
		dfs(nx,ny);
	}
}

int main(){
	while(cin >> w >> h, w){
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin >> c[i][j];
		int ans = 0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(c[i][j]) ans++, dfs(i,j);
		cout << ans << endl;
	}
}