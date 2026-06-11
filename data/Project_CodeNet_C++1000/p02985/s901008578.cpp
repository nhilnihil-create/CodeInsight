#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100100;
const int mod = 1e9+7;
ll n,k;
vector<ll> edge[N];
//ll fa[N];
bool vis[N];
ll tot;
ll child[N]; 
bool flag;
void getbrother()
{
	child[1]=edge[1].size();
	for(int i=2;i<=n;i++)
		child[i]=edge[i].size()-1;
}
void dfs(int node, int depth)
{
	vis[node]=true;
	int brother = child[node]-1;
	int now = -1;
	for(int i=0;i<edge[node].size();i++)
	{
		ll v = edge[node][i];
		if(vis[v])	continue;
		dfs(v,depth+1);
		now++;
		if(!flag)	return;
		ll fa = depth==1? 1:2;
		if(k-brother-fa<0)
		{
			flag=false;
			return ;
		}	
		tot = (tot*(k-now-fa))%mod;
	}
	return ;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	ll u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	memset(vis,false,sizeof(vis));
	tot = k;
	getbrother();
	flag=true; 
	dfs(1,1); 
	if(!flag)	printf("0\n");
	else printf("%lld\n",tot); 
	return 0;
}