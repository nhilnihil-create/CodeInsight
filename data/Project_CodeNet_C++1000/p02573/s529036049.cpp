#include<bits/stdc++.h>                                                   //---------------------------------------------------------------

# define ll long long
# define mod 1000000007
# define MAX 100005
# define PI 3.141592653589793238                                                                                  //shortcut keys

# define pb push_back
# define mp make_pair
# define all(x) x.begin(),x.end()
# define fr(i,a,b) for(int i=a;i<=b;i++)

# define decimal(k) fixed<<setprecision(k)
# define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);        //---------------------------------------------------------------
using namespace std;
vector<int> g[200005];
int done[200005]={};
int x=0;
void dfs(int u){
	done[u]=1;x++;
	for(auto v:g[u]){
		if(done[v])continue;
		dfs(v);
	}
}
int main()
{
	
	int n,m;cin>>n>>m;
	fr(i,1,m){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=0;
	fr(i,1,n){
		x=0;
		if(done[i])continue;
		dfs(i);
		ans=max(ans,x);
	}
	cout<<ans<<'\n';

	return 0;
}

