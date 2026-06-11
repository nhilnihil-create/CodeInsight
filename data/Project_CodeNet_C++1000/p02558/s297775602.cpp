#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007

struct DisjointSet
{
	ll n;
	vector<ll> parent;
	vector<ll> rank;
	DisjointSet(ll num)
	{
		n=num;
		for(ll i=0;i<n;i++)
		{
			parent.push_back(i);
			rank.push_back(1);
		}
	}
	ll find(ll x)
	{
		if(parent[x]==x)	return x;
		parent[x]=find(parent[x]);
		return parent[x];
	}
	void unionSet(ll a,ll b)
	{
		ll parent_a=find(a);
		ll parent_b=find(b);
		if(parent_a==parent_b)	return;
		if(rank[parent_a]>rank[parent_b])
		{
			parent[parent_b]=parent_a;
		}
		else if(rank[parent_a]<rank[parent_b])
		{
			parent[parent_a]=parent_b;
		}
		else
		{
			parent[parent_a]=parent_b;
			rank[parent_b]++;
		}
	}
};
int main() 
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,q;
    cin>>n>>q;
    DisjointSet s(n);
    while(q--)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	if(a==0)
    	{
    		s.unionSet(b,c);
    	}
    	else
    	{
    		if(s.find(b)==s.find(c))
    		{
    			cout<<1<<endl;
    		}
    		else
    		{
    			cout<<0<<endl;
    		}
    	}
    }
	return 0;
}