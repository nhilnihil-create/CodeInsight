#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

int d[100000] ;
int visited[100000] ;
int parent[100000] ;

void bfs(int source,vector<vector<int>> &adj,int n){

	queue<int> q ; 
	q.push(source) ;
	d[source]=0 ;
	parent[source]=-1 ;
	visited[source]=1 ;

	while(!q.empty()){

		int t=q.front() ;
		q.pop() ;

		for(auto x: adj[t]){

			if(visited[x]==0){
				q.push(x) ;
				visited[x]=1 ;
				parent[x]=t ;
				d[x]=d[t]+1 ;
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(i!=source && d[i]==0){
			cout<<"No" ;
			return ;
		}
	}

	cout<<"Yes"<<"\n" ;
	
	for(int i=2;i<=n;i++){
		cout<<parent[i]<<"\n" ;
	}		
}

void solve(){
	
	int v,e ;
	cin>>v>>e ;

	vector<vector<int>> adj(v+1) ;

	for(int i=0;i<e;i++){
	
		int l,r ;
		cin>>l>>r ;

		adj[l].push_back(r) ;
		adj[r].push_back(l) ;

	}

	for(int i=1;i<=v;i++){
	
		d[i]=0 ;
		visited[i]=0 ;
		parent[i]=0 ;
	
	}


	bfs(1,adj,v) ;

}


int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}