#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 

vector<pll>v;
ll h[500005],sm[500005],b[500005];

int main()
{
    ios_base::sync_with_stdio(false);
	ll n,i,j,k,x,y,t,m,l,r;

	cin >> n >> k;
	string s;

	cin >> s;

	i=0,n=sz(s);
	while(i<n)
	{
		j=i;
		while(j<n && s[j]==s[i])j++;
		v.pb({s[i],j-i});
		i=j;
	}

	for(i=0;i<sz(v);i++)
	{
		h[i]=v[i].ss-1;
		sm[i]=v[i].ss;
		if(i)
			h[i]+=h[i-1],sm[i]+=sm[i-1];
	}

	for(i=sz(v)-1;i>=0;i--)
	{
		b[i]=v[i].ss-1;
		if(i+1<sz(v))
			b[i]+=b[i+1];
	}

	ll mx=0;
	l=0,r=0;
	while(r<sz(v))
	{
		x=(r-l)/2+1;
		if(x>k)
			l+=2;

		y = 0;
		if(r+2<sz(v))
			y+=b[r+2];
		if(l-2>=0)
			y+=h[l-2];

		if(r+1<sz(v))
			y+=sm[r+1];
		else
			y+=sm[r];

		if(l-2>=0)
			y-=sm[l-2];

		mx=max(mx,y);
		r+=2;
	}
	l=1,r=1;
	while(r<sz(v))
	{
		x=(r-l)/2+1;
		if(x>k)
			l+=2;

		y = 0;
		if(r+2<sz(v))
			y+=b[r+2];
		if(l-2>=0)
			y+=h[l-2];

		if(r+1<sz(v))
			y+=sm[r+1];
		else
			y+=sm[r];

		if(l-2>=0)
			y-=sm[l-2];

		mx=max(mx,y);
		r+=2;
	}
	cout<<mx-1<<endl;
}