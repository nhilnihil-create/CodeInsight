#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
ll bg = 20000001;
#define ff(i,n) for(i=0;i<n;i++) 
void dfs(ll i,ll vis[],ll p[],vector<vector<ll> > &adj,ll par)
{
	vis[i] = 1;
	p[i] = par;
	ll j;
	for(j=0;j<adj[i].size();j++)
	{
		if(vis[adj[i][j]]==0)
		{
			dfs(adj[i][j],vis,p,adj,i);
		}
	}
}
ll dp[140000][26];
string s;
ll fun(ll l,ll r,ll alpha)
{
	ll mid = (l+r)/2;
	if(l==r)
	{
		if((s[l-1]-'a')!=alpha)
		   return 1;
		else
		   return 0;   
	}
	ll l1 = ((r-mid)-(dp[r][alpha]-dp[mid][alpha])) + fun(l,mid,alpha+1);
	ll l2 = ((mid-l+1)-(dp[mid][alpha]-dp[l-1][alpha])) + fun(mid+1,r,alpha+1);
	ll l3 = min(l1,l2);
	return l3;
}
int main()
{
	ll test,t;
	t=1;
	for(test=1;test<=t;test++)
	{
		ll i,n,a=0;
		cin>>n;
		ll arr[n];
		ff(i,n)
		    cin>>arr[i];
		ff(i,n)
		    if(i%2==0 && arr[i]%2==1)    
		      a++;
		cout<<a;      
	}
	return 0;
} 