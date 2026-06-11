//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <utility>

#define INF INT_MAX / 2
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool used[30][30];

int bfs(int sy,int sx,const vector<vector<int> >&tiles){
	queue<pair<int,int> > q;
	q.push(make_pair(sy,sx));
	int X = tiles[0].size();
	int Y = tiles.size();
	memset(used,0,sizeof(used));
	used[sy][sx] = true;
	int ret= 0;
	while(!q.empty()){
		P p = q.front();q.pop();
		int y = p.first;int x = p.second;
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if( ny < 0 || nx < 0 || ny >= Y || nx >= X || used[ny][nx] || tiles[ny][nx]==0)continue;
			used[ny][nx] = true;
			q.push(make_pair(ny,nx));
			ret++;
		}
	}
	return ret+1;
}

int main(void) {
	int w,h;
	while(cin >> w >> h,w+h!=0){
	vector<vector<int> >tiles(h,vector<int>(w));
	int sx,sy;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char c;cin >> c;
			if(c=='.')
				tiles[i][j] = 1;
			else if(c=='#')
				tiles[i][j] = 0;
			else{
				tiles[i][j] = 1;
				sx = j;sy = i;
			}
		}
	}
	cout << bfs(sy,sx,tiles) << endl;
}
}

// command ctrl 上下
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));