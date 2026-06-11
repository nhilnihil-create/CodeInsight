#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > adj(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v; u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n);
	vector<int> p(n);
	queue<int> q;
	q.push(0);vis[0]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int ni:adj[x]){
			if(!vis[ni]){
				vis[ni]=vis[x]+1;
				q.push(ni);
				p[ni]=x;
			}
		}
	}
	for(int d:vis){
		if(!d){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<n;i++) cout<<p[i]+1<<' ';

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    //while(t--) cout<<solve()<<'\n';
    while(t--) solve(),cout<<'\n';
    return 0;
}
