#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> P;
const int POINT = 300000;
struct Edge{int to;int cost;};
void Dijk(vector<Edge> G[],int s,int res[POINT]){
	bool vis[POINT]={0};
	fill(res,res+POINT,-3);
	priority_queue<P,vector<P>,greater<P>> que;
	P p;
	vis[s]=true;
	res[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		p = que.top();
		que.pop();
		for(Edge e:G[p.second]){
			if(!vis[e.to] || res[e.to]>res[p.second]+e.cost){
				vis[e.to]=true;
				res[e.to]=res[p.second]+e.cost;
				que.push(P(res[e.to],e.to));
			}
		}
	}
}
int main(){
	int N,M,S,T,u,v;
	int ans[POINT];
	vector<Edge> G[POINT];
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>u>>v;u--;v--;
		G[u].push_back({v+N,1});
		G[u+N].push_back({v+2*N,1});
		G[u+2*N].push_back({v,1});
	}
	cin>>S>>T;S--;T--;
	Dijk(G,S,ans);
	cout<<ans[T]/3;
	return 0;
}