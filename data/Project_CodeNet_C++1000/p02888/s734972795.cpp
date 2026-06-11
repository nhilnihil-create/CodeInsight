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

vector<ll>v;
ll c[5000],p[5000];

int main()
{
    ios_base::sync_with_stdio(false);
	ll n,i,j,k,x,y,t,m;

	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		v.pb(x);
		c[x]++,p[x]++;
	}

	for(i=1;i<=4000;i++)
		c[i]+=c[i-1];


	ll ans=0;

	for(i=1;i<=1000;i++)
	{
		if(p[i]>1)
		{
			x = (p[i]*(p[i]-1))/2;
			y = c[2*i-1]-p[i];
			ans += x*y;
		}
		if(p[i]>2)
		{
			y = (p[i]*(p[i]-1)*(p[i]-2))/6;
			ans += y;
		}
	}

	for(i=1;i<=1000;i++)
	{
		for(j=i+1;j<=1000;j++)
			ans+=(c[i+j-1]-c[j])*p[i]*p[j];
	}

	cout<<ans<<endl;
}