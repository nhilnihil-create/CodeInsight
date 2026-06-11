#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxn=1e5+1;
ll n,m;
vector<ll>g[mxn];
vector<bool>used(mxn,false);
int ans=0;
void dfs(int u)
{
	used[u]=true;
	for(ll i:g[u])
		if(!used[i])
			dfs(i);
}
void solve(){
	cin>>n>>m;
	while(m--)
	{
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(ll i=1;i<=n;i++)
		if(!used[i])
	      dfs(i),++ans;
	cout<<ans-1;

}
int main(){
	solve();
}
