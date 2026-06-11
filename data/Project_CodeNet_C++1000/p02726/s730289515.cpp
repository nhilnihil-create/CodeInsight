#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2100;
int n, x, y, a, b;
set<pair<int, int>> resp[MAXN];
int mark[MAXN];

void bfs(int u){
	memset(mark, -1, sizeof(mark));
	queue<int> Q;
	Q.push(u);
	mark[u] = 0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		resp[mark[v]].insert({min(u, v), max(u, v)});
		if (v < n-1 && mark[v+1] == -1){
			mark[v+1] = mark[v] + 1;
			Q.push(v+1);
		}
		if (v > 0 && mark[v-1] == -1){
			mark[v-1] = mark[v] + 1;
			Q.push(v-1);
		}
		if(v == x && mark[y] == -1){
			mark[y] = mark[v]+1;
			Q.push(y);
		}
		if (v == y && mark[x] == -1){
			mark[x] = mark[v]+1;
			Q.push(x);
		}
	}
}

int main(){
	//memset(resp, 0, sizeof(resp));
	cin >> n >> a >> b;
	a--; b--;	
	x = min(a, b);
	y = max(a, b);

	for (int i = 0; i < n; i++){
		bfs(i);
	}

	for (int i = 1; i < n; i++){
		//cout << "I ----- " << i << endl;
		cout << resp[i].size() << endl;
	}
	return 0;
}