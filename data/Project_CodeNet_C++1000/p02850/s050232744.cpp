#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
typedef pair<lint, lint> P;

signed main(){
	lint N; cin >> N;
	vector<vector<lint> > G(N);
	vector<P> vec;
	for(lint i = 1; i < N; i++){
		lint a, b; cin >> a >> b; --a; --b;
		G[a].push_back(b); G[b].push_back(a);
		vec.push_back(P(a, b));
	}
	vector<lint> color(N, 0), used(N, -1);
	lint MAX_COLOR = 0;
	queue<lint> que;
	used[0] = 1; que.push(0);
	map<P, lint> MAP;
	while(que.size()){
		lint now = que.front(); que.pop();
		lint num = 1;
		MAX_COLOR = max(MAX_COLOR, lint(G[now].size()));
		for(lint i = 0; i < G[now].size(); i++){
			lint next = G[now][i];
			if(used[next] != -1) continue;
			if(color[now] == num) num++;
			color[next] = num;
			MAP[P(now, next)] = num;
			MAP[P(next, now)] = num;
			num++;
			used[next] = 1;
			que.push(next);
		}
	}
	cout << MAX_COLOR << endl;
	for(auto value : vec) cout << MAP[value] << endl;
}