#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Edge{
	int from,to;
	T cost;
	Edge(int to,T cost) : to(to),cost(cost){}
	Edge(int from,int to,T cost) : from(from),to(to),cost(cost){}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;

vector<int> topologicalSort(const Graph &G){
	int n = G.size();
	vector<int> in(n),ret;
	queue<int> que;
	for(int i = 0;i < n;i++){
		for(int to : G[i]) in[to]++;
	}
	for(int i = 0;i < n;i++){
		if(!in[i]) que.push(i);
	}
	while(!que.empty()){
		int v = que.front(); que.pop();
		ret.push_back(v);
		for(int to : G[v]){
			in[to]--;
			if(!in[to]) que.push(to);
		}
	}
	return ret;
}

signed main(){
	int n,m;
	cin >> n >> m;
	Graph G(n);
	for(int i = 0;i < m;i++){
		int s,t;
		cin >> s >> t;
		G[s].push_back(t);
	}
	auto topo = topologicalSort(G);
	for(int v : topo) cout << v << endl;
}
