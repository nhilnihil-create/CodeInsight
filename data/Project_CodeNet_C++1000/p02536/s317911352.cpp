#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm> 

using namespace std;

const int maxn = 1e5 + 10;

int fa[maxn],vis[maxn];

int n,m;

int x,y;

int ans;

int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void Union(int x,int y) {
	int xx = get(x);
	int yy = get(y);
	if(xx == yy) return;
	fa[yy] = xx;
	return ;
}

int main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		fa[i] = i;
	}
	for(int i = 1; i <= m; i ++) {
		cin >> x >> y;
		if(get(x) == get(y)) continue;
		else {
			Union(x,y);
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(fa[i] == i) ans++;
	}
	cout << ans - 1 << endl;
	return 0;
}