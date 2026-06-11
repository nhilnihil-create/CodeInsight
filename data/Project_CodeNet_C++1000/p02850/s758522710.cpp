#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int> > G;
typedef pair<int, int> P;

int main(){
	int n; scanf("%d", &n);
	G.resize(n);
	vector<P> vec;
	for(int i = 0; i < n - 1; i++){
		int a, b; scanf("%d %d", &a, &b); 
		--a; --b;
		G[a].push_back(b); G[b].push_back(a);
		vec.push_back(P(a, b));
	}
	vector<int> used(n, 0), color(n);
	int MAX_COLOR = 0;
	queue<int> que;
	used[0] = 1; que.push(0);
	map<P, int> MAP;
	while(que.size()){
		int now = que.front(); que.pop();
		int num = 1;
		MAX_COLOR = max(MAX_COLOR, int(G[now].size()));
		for(auto next : G[now]){
			if(used[next]) continue;
			if(color[now] == num) num++;
			color[next] = num;
			MAP[P(now, next)] = num;
			MAP[P(next, now)] = num;
			num++;
			used[next] = 1;
			que.push(next);
		}
	}
	printf("%d\n", MAX_COLOR);
	for(auto value : vec) printf("%d\n", MAP[value]);
}