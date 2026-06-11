#include  <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

const int vmax=10010;

int N,M;
vector<int> graph[vmax];

bool used[vmax];

void dfs(int v,vector<int>& order){
	used[v]=true;
	for(auto &u:graph[v]){
		if(!used[u])
			dfs(u,order);
	}
	order.push_back(v);
}

void topologicalSort(vector<int>& order) {
	rep(i,N) used[i]=false;
	rep(i,N)if(!used[i]) dfs(i,order);
	reverse(order.begin(),order.end());
}

int main(void){
	cin >> N >> M;
	rep(i,M){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	vector<int> order;
	topologicalSort(order);
	for(auto &v:order) cout << v << endl;
	return 0;
}