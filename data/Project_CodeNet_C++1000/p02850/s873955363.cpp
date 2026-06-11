#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
 
using namespace std;

vector<pii> adj[100001];
int color[100001];
bool vis[100001];

void dfs(int s, int v){
	vis[s] = 1;
	int tmp = 1;
	for(auto x: adj[s]){
		if(vis[x.f] == 0){
			if(tmp<v){
				dfs(x.f,tmp);
				color[x.s] = tmp;
			}
			else{
				dfs(x.f,tmp+1);
				color[x.s] = tmp+1;
			}
			tmp++;
		}
	}
}

void solve(){
	int n; cin>>n;
	int mm  = INT_MIN;
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y;
		adj[x].pb({y,i});
		adj[y].pb({x,i});
		mm = max(mm,(int)adj[x].size());
		mm = max(mm,(int)adj[y].size());
	}
	int r;
	for(int i=0; i<n; i++){
		if(adj[i+1].size() == 1){
			r = i+1;
			break;
		}
	}
	cout<<mm<<"\n";
	dfs(r,1e6);
	for(int i=0; i<n-1;i++){
		cout<<color[i]<<"\n";
	}


}


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	
	int t =1; 
	//cin>>t;

	for(int i=1; i<=t; i++){
		solve();
		cout<<"\n";
	}
	return 0;

}