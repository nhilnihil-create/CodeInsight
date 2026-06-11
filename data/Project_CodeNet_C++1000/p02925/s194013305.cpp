#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v[500005],rv[500005];
int a[1005][1005],id[1005][1005],dp[500005];
bool vis[500005];
V<int> t;
void dfs(int p){
	if(vis[p])RE;
	vis[p]=1;
	for(auto u:v[p])if(!vis[u])dfs(u);
	t.PB(p);
}
void rdfs(int p,int k){
	if(vis[p])RE;
	vis[p]=1;
	for(auto u:rv[p]){
		if(!vis[u])rdfs(u,k);
		gmax(dp[p],dp[u]+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,cnt=0;
	cin>>n;
	rep(i,1,n)FOR(j,i+1,n)id[i][j]=id[j][i]=++cnt,dp[cnt]=1;
	FOR(i,1,n){
		rep(j,1,n)cin>>a[i][j];
		rep(j,1,n-1)v[id[i][a[i][j]]].PB(id[i][a[i][j+1]]);
	}
	FOR(i,1,cnt)for(auto u:v[i])rv[u].PB(i);
	FOR(i,1,cnt)if(!vis[i])dfs(i);
	reverse(ALL(t));
	int k=0;FILL(vis,0);
	for(auto u:t)if(!vis[u])rdfs(u,++k);
	if(k<cnt){
		cout<<-1;RE 0;
	}
	int ans=0;
	FOR(i,1,cnt)gmax(ans,dp[i]);
	cout<<ans;
	RE 0;
}


