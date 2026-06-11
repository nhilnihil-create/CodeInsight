#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pi;
vector<long long>tree[100005];
vector<pi>edge;
map<pi,int>m;
bool visited[100005];
void dfs(int curr,int used){
	visited[curr] = true;
	int counter = 1;
	for(int i=0; i<tree[curr].size(); i++){
		if(counter==used) counter++;
		long long next = tree[curr][i];
		if(!visited[next]){
			m.insert(make_pair(pi(curr,next),counter));
			m.insert(make_pair(pi(next,curr),counter));
			dfs(next,counter);
			counter++;
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++){
		long long a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		edge.push_back(pi(a,b));
	}	
	int maxcolor = 0;
	for(int i=1; i<=n; i++) maxcolor = max(maxcolor,(int)tree[i].size());
	dfs(1,0);
	cout<<maxcolor<<'\n';
	for(int i=0; i<edge.size(); i++){
		cout<<m.find(edge[i])->second<<'\n';
	}
}