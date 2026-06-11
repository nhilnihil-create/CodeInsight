#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M = 2e5+5;
ll d[M],c[M];
int pos[20];
pair<ll,ll> solve(ll s,ll d,ll n)
{
	vector<ll> v,val;
	memset(pos,-1,sizeof(pos));
	int cyc = 0;
	while(1)
	{
		ll z = s+d;
		ll vl = 1;
		if(z>9)
		{
			vl++;
			z = (1+z%10);
		}
		if(pos[z]!=-1)
		{
			cyc = pos[z];
			break;
		}
		val.pb(vl);
		pos[z] = sz(v);
		v.pb(z);
		s=z;
	}
	ll res = 0;
	for(int i=0;i<cyc;i++)
	{
		res += val[i];
		n--;
		if(n==0)
			return {res,v[i]};
	}
	int len = (sz(v)-cyc);
	int ret = -1;
	for(int i=cyc;i<cyc+(n%len);i++)
	{
		res+=val[i];
		ret = v[i];
	}
	// if(d==1)
	// 	cout<<res<<endl;
	ll sum=0;
	for(int i=cyc;i<sz(v);i++)
		sum+=val[i];
	if(ret==-1)
		ret = v[sz(v)-1];
	res += sum*(n/(ll)len);
	return {res,ret};
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>d[i]>>c[i];
	int cur;
	ll ans = 0;
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		{
			cur = d[i];
			if(c[i]>1)
				c[i]--;
			else
				continue;
		}
		auto rval = solve(cur,d[i],c[i]);
		ans += rval.ff;
		cur = rval.ss;
		// cout<<ans<<" "<<cur<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}