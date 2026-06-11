#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 50;
int bigo[5][5], vis[5][5], n;
pair<int, int> pos[150];
int main() {
	
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			scanf("%d", &bigo[i][j]);
			pos[bigo[i][j]] = make_pair(i, j);
		}
	}
	
	cin >> n;
	int x;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		vis[pos[x].first][pos[x].second] = 1;
	}
	
	bool f = 0;
	for(int i = 1; i <= 3; i++) {
		if(vis[i][1] && vis[i][2] && vis[i][3]) f = 1;
		if(vis[1][i] && vis[2][i] && vis[3][i]) f = 1;
	}
	if(vis[1][1] && vis[2][2] && vis[3][3]) f = 1;
	if(vis[3][1] && vis[2][2] && vis[1][3]) f = 1;
	if(f) puts("Yes");
	else puts("No"); 
	return 0;
} 
