#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
ll n,x,y,q,h,j;
vector<ll> g[200005];
ll v[200005];
void dfs(ll i,ll p){
	for(ll x:g[i]){
		if(x==p) continue;
		v[x]+=v[i];
		dfs(x,i);
	}
}
int main(){
	cin>>n>>q;
	for(int i=0;i<n-1;i++) cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	while(q--){
		cin>>h>>j;
		v[h]+=j;
	}
	dfs(1,0);
	for(ll i=1;i<=n;i++) cout<<v[i]<<" ";
}
