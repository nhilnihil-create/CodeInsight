#include <bits/stdc++.h>
using namespace std;
const long long INF = 123456789987654321;
const int MAX = 123456;
struct edge {
	long long cost;
	int from, to;
};
int v, e, r;
edge ed[MAX];
long long dist[MAX];
void bellmanford(int s) {
	fill(dist, dist + MAX, INF);
	dist[s] = 0;
	int cnt = 0;
	while(true) {
		bool up = false;
		cnt++;
		for(int i = 0; i < e; i++) {
			edge tmp = ed[i];
			if(dist[tmp.from] != INF && dist[tmp.to] > dist[tmp.from] + tmp.cost) {
				dist[tmp.to] = dist[tmp.from] + tmp.cost;
				up = true;
			}
		}
		if(!up) {
			break;
		}
		if(cnt == v) {
			cout << "NEGATIVE CYCLE" << endl;
			exit(0);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cin >> v >> e >> r;
	for(int i = 0; i < e; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		ed[i] = edge{d, s, t};
	}
	bellmanford(r);
	for(int i = 0; i < v; i++) {
		if(dist[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
	return 0;	
}

