#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<int>tree[100005];
map<pi,int>m;
vector<pi>edge;
bool visited[100005];

void dfs(int curr, int used_color){
	visited[curr] = true;
	int color = 1;
	for(int i=0; i<tree[curr].size(); i++){
		int child = tree[curr][i];
		if(!visited[child]){
			if(color==used_color) color++;
			m.insert(make_pair(pi(curr,child),color));
			m.insert(make_pair(pi(child,curr),color));
			dfs(child,color++);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		edge.push_back(pi(a,b));
	}
	int mx = 0;
	for(int i=1; i<=n; i++) mx = max(mx,(int)tree[i].size());
	dfs(1,0);
	cout<<mx<<'\n';
	for(int i=0; i<edge.size(); i++){
		cout<<m.find(pi(edge[i].first,edge[i].second))->second<<'\n';
	}
}