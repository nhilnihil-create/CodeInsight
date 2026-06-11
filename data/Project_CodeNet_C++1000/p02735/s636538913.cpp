#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> ti;
const int INF = 1e9;
const int MN = 110;
int g[MN][MN];
int dx[2] = {1,0};
int dy[2] = {0,1};
int dist[MN][MN];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int h,w;
	cin >> h >> w;
	for(int i=0;i<h;i++) {
		string s;
		cin >> s;
		for(int j=0;j<w;j++) {
			if(s[j] == '#') {
				g[i][j] = 0;
			} else {
				g[i][j] = 1;
			}
			dist[i][j] = INF;
		}
	}
	priority_queue<ti,vector<ti>,greater<ti> > lol;
	int be = 1-g[0][0];
	dist[0][0] = be;
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			int ad = ((g[i][j] && !g[i+1][j])?1:0);
			dist[i+1][j] = min(dist[i][j]+ad,dist[i+1][j]);
			int bd = ((g[i][j] && !g[i][j+1])?1:0);
			dist[i][j+1] = min(dist[i][j]+bd,dist[i][j+1]);
		}
	}
	cout << dist[h-1][w-1] << '\n';
}
