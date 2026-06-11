#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int MAX=10002;
int V,E;
int indeg[MAX]={0},inq[MAX]={0};
vector<int> out,G[MAX];
void bfs(int s){
	queue<int> Q;
	Q.push(s);
	inq[s]=1;
	while (!Q.empty()){
		int u=Q.front();
		out.push_back(u);
		Q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			indeg[v]--;
			if(!indeg[v] && !inq[v]){
				Q.push(v);
				inq[v]=1;
			}
		}
	}
}
void topologicalSort(){
	for(int i=0;i<V;i++){
		if(!indeg[i]&&!inq[i])
			bfs(i);
	}
}
int main(){
	cin>>V>>E;
	int s,t;
	for(int i=0;i<E;i++){
		cin>>s>>t;
		G[s].push_back(t);
		indeg[t]++;
	}
	topologicalSort();
	for(int i=0;i<V;i++){
		cout<<out[i]<<endl;
	}
	return 0;
} 
