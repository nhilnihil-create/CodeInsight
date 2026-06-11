//abc132_e.cpp
//Wed May 13 22:06:42 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,m;
	cin >> n >> m;

	vector<int> edge[3*n];

	for (int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		edge[u].push_back(v+n);
		edge[u+n].push_back(v+2*n);
		edge[u+2*n].push_back(v);
	}

	int s,t;
	cin >> s >> t;
	s--;t--;
	int dist[3*n];
	fill(dist,dist+3*n,-1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int cur = q.front(); q.pop();
		for (int i=0;i<edge[cur].size();i++){
			int tmp = edge[cur][i];
			if (dist[tmp]==-1){
				dist[tmp] = dist[cur]+1;
				q.push(tmp);
			}
		}
	}
	if (dist[t]==-1){
		cout << -1 << endl;
	}else {
		cout << dist[t]/3 << endl;
	}
//	printf("%.4f\n",ans);
}