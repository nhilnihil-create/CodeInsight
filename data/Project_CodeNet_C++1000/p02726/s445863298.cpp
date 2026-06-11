#include<bits/stdc++.h>
using namespace std;




int main(){

	int n,x,y;
	cin>>n>>x>>y;
	x -= 1;
	y -= 1;
	vector<vector<int> > graph(n);
	for(int i=0;i<n-1;i++){
		graph[i].push_back(i+1);
		graph[i+1].push_back(i);
	}
	graph[x].push_back(y);
	graph[y].push_back(x);
	vector<int> ans(n);
	vector<int> dist(n);
	vector<int> visited(n);
	queue<pair<int,int> > que;
	
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++)
			visited[i] = 0;
		for(int i=0;i<n;i++)
			dist[i] = n+10;
		dist[j] = 0;
		que.push(make_pair(j,0));
		//dist[x] = 0;
		while(!que.empty()){
			pair<int,int> a = que.front();
			que.pop();
			if(visited[a.first])
				continue;
			visited[a.first] = 1;
			//que.pop();
			//cout<<"============================="<<endl;
			dist[a.first] = min(dist[a.first],a.second + 1);
			for(int i=0;i<graph[a.first].size();i++){
				que.push(make_pair(graph[a.first][i],dist[a.first]));
			}
		}
		for(int i=0;i<n;i++){
			int b = dist[i];
			ans[b] += 1;
		}
	}
	for(int i=1;i<=n-1;i++){
		cout<<ans[i]/2<<endl;
	}
	
	
	
	return 0;
  
}