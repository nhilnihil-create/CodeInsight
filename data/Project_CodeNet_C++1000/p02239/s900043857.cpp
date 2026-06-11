#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX_NODE 10000
#define INF 1000000000

using namespace std;

int d[MAX_NODE];
vector<int> adj[MAX_NODE];

int bfs(int n, int start){
	queue<int> que;
	for(int i=0;i<n;i++){
		d[i]=(i==start)?0:-1;
	}
	que.push(start);
	while(que.empty()==0){
		int from=que.front();
		que.pop();
		for(int i=0;i<adj[from].size();i++){
			int to=adj[from][i];
			if(d[to]==-1){
				d[to]=d[from]+1;
				que.push(to);
			}
		}
	}
}	

int main(){
	int n,u,k,v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>u>>k;
		for(int j=0;j<k;j++){
			cin>>v;
			v--;
			adj[u-1].push_back(v);
		}
	}
	bfs(n,0);
	for(int i=0;i<n;i++){
		cout<<i+1<<" "<<d[i]<<endl;
	}
	return 0;
}