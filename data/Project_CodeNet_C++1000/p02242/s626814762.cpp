#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct Edge{ int to,cost; };

typedef pair<int,int> P;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void dijkstra(Graph &G,vector<int> &d,int n,int s){
	priority_queue< P, vector<P>, greater<P> > que;
	fill(d.begin(),d.end(),INT_MAX);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();
		que.pop();
		
		int a=p.second;
		if (d[a]<p.first){
			continue;
		}
		for (int i=0;i<G[a].size();i++){
			Edge e = G[a][i];
			if (d[e.to]>d[a]+e.cost){
				d[e.to]=d[a]+e.cost;
				P p2=P(d[e.to],e.to);
				que.push(p2);
			}
		}
	}
}

int main(){
	int n,i,j,k;
	vector<int> d(n);
	Edge e;
	
	cin >> n;
	
	Graph G(n);
	
	for (i=0;i<n;i++){
		cin >> k >> k;
		for (j=0;j<k;j++){
			cin >> e.to >> e.cost;
			G[i].push_back(e);
		}
	}
	
	dijkstra(G,d,n,0);
	
	for (i=0;i<n;i++){
		cout << i << " " << d[i] << endl;
	}
	
	return 0;
}