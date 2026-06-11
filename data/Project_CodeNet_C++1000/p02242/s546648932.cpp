#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge {int to, cost;};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int mind(vector<int> &a,vector<int> &b){
	int n=a.size();
	int min=INT_MAX;
	int ind=0;
	for (int i=0;i<n;i++){
		if((min>a[i])&&(b[i]==0)){
			min=a[i];
			ind=i;
		}
	}
	if(min==INT_MAX){
		return -1;
	}else{
		return ind;
	}
}

int min(vector<int> &a){
	int n=a.size();
	int min=a[0];
	int ind=0;
	for (int i=0;i<n;i++){
		if(min>a[i]){
			min=a[i];
			ind=i;
		}
	}
	return min;
}

void dijkstra(Graph &G,vector<int> &d,int n,int s){
	fill(d.begin(),d.end(),INT_MAX);
	vector<int> c(n,0);
	int t;
	
	d[s]=0;
	
	while((t=mind(d,c))!=-1){
		c[t]=1;
		for(int i=0;i<G[t].size();i++){
			Edge e=G[t][i];
			if(d[e.to] > d[t]+e.cost){
				d[e.to] = d[t]+e.cost;
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