#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x) (x).begin(),(x).end()


void dfs(vector<vector <ll>> &v,ll p ,vector <bool> &vis)
{

vis[p]=true;

for(auto it=v[p].begin();it!=v[p].end();++it)
{
if(vis[*it]==false)
	dfs(v,*it,vis);

}

}


int main()
{
fast;
ll n,m;
cin>>n>>m;

vector <vector <ll>> v(n+1);

for(int i=1;i<=m;i++)
{
ll x,y;
cin>>x>>y;
v[x].push_back(y);
v[y].push_back(x);
	
}

vector <bool> vis(n+1,false);

ll ans=0;

for(int i=1;i<=n;i++)
{
if(vis[i])continue;
dfs(v,i,vis);
ans++;

}

cout<<ans-1<<endl;
		
}

