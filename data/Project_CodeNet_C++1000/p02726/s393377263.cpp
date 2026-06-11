#include <bits/stdc++.h>

using namespace std;

const int N=2e3+5;
vector<int>g[N];
int ans[N];
int n,x,y;

void solve(int i){
	vector<int> used(n),dist(n,0);
	queue<int>q;
	q.push(i);
	used[i]=1;
	while(q.size()>0){
		int v=q.front();
		q.pop();
		if(v>i){
			ans[dist[v]]++;
		}
		for(auto to : g[v]){
			if(!used[to]){
				used[to]=1;
				dist[to]=dist[v]+1;
				q.push(to);
			}
		}
	}
}

int main(){
	cin>>n>>x>>y;
	--x,--y;
	for(int i=0;i<n-1;i++){
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	g[x].push_back(y);
	g[y].push_back(x);
	
	for(int i=0;i<n;i++){
		solve(i);
	}
	for(int i=1;i<n;i++){
		cout<<ans[i]<<'\n';
	}



}