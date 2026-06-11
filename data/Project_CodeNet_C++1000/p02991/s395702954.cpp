#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
typedef pair<lint, lint> P;

signed main(){
	lint N, M; cin >> N >> M;
	vector<vector<lint> > G(N);
	for(lint i = 0; i < M; i++){
		lint u, v; cin >> u >> v; --u; --v;
		G[u].push_back(v); 
	}
	lint s, t; cin >> s >> t; --s; --t;
	vector<vector<lint> > dist(N, vector<lint> (3, INF));
	queue<P> que;
	que.push(P(s, 0)); dist[s][0] = 0;

	while(que.size()){
		P p = que.front(); que.pop();
		lint now = p.first, num = p.second;
		for(auto next : G[now]){
			lint num_next = (num + 1) % 3;
			if(dist[next][num_next] == INF){
				dist[next][num_next] = dist[now][num] + 1;
				que.push(P(next, num_next));
			}
		}
	}

	lint ans = dist[t][0];
	if(ans == INF) cout << -1 << endl;
	else cout << ans/3 << endl;
}