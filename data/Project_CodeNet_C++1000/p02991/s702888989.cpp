#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> edge[100005];
int n,m,s,t,vis[100005][3];
void bfs(){
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first;
		int x=q.front().second;
		q.pop();
		if(u==t&&x%3==0){
			cout<<x/3<<endl;
			exit(0);
		}
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i],val=x+1;
			if(vis[v][val%3]==1) continue;
			q.push({v,val});
			vis[v][val%3]=1;
		}
	}

}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
	}
	cin>>s>>t;
	bfs();
	cout<<-1<<endl;
}