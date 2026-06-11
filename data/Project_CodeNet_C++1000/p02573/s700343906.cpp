#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
const ll mod = 1e9+7;
const int N = 2e5+205;
vector<int>v[N];
bool vis[N];
int sz;
int ans;
void dfs(int x){
	vis[x] = true;
	sz++;
	ans = max(ans,sz);
	for(int y:v[x]){
		if(!vis[y])dfs(y);
	}
}
void solve(){
	int n,m; 
	cin>>n>>m; 
	for(int i=1;i<=m;i++){
		int x,y; 
		cin>>x>>y; 
		v[x].pb(y);
		v[y].pb(x);
	}
	ans = 1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sz = 0;
			dfs(i);
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
