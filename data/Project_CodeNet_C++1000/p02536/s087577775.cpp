#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for( ll i=a;i<n;++i)
#define pb push_back
#define ll long long
#define vi vector<ll>

vi adj[1000001];
ll vis[1000001];

ll ans=0;
void dfs( ll node)
{
	vis[node] =1;
  	for( ll child:adj[node])
    {
		if(!vis[child])
        {
			vis[child] =1;
          dfs(child);
        }
    }
}


void solve()
{
ll n,m; cin>>n>>m;
  rep(i,0,m)
  {
	ll a,b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  rep(i,1,n+1)
  {
	if(!vis[i])
    {
		ans++;
      dfs(i);
    }
  }
  
  cout<<ans-1;
}
int main(){
  ll tt=1;
  while(tt--)
  {
		solve();
    	cout<<"\n";
  }


}