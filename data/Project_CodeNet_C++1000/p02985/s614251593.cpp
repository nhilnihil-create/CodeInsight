#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007

vector<ll>v[100005];

ll dfs(ll k,ll now,ll p)
{
	ll x;
	if(p==-1)
		x=k-1;
	else
		x=k-2;
	if(v[now].size()>k)
		return 0;
	else
	{
		ll y=1;
		for(auto e:v[now])
		{	if(e==p)
				continue;
			y=y*x;
			x--;
			y%=mod;


		}

	
	for(auto e:v[now])
	{
		if(e==p)
			continue;
		y*=dfs(k,e,now);
		y%=mod;
	}
	return y;
}

}
int main() {
	ll n,k;
	cin>>n>>k;
	//vector<ll>v[n+1];
	for(int i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);

	}
ll ans=k*dfs(k,0,-1);
ans%=mod;
cout<<ans;
	
}
