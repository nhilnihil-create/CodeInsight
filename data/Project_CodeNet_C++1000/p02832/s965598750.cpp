#include<bits/stdc++.h>
#define ll long long int
#define vll vector<pair<ll, ll> >
#define vl vector<ll>
#define vi vector<int>
#define vii vector<pair<int, int> >
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
using namespace std;

ll power_mod(ll x, ll y, ll p)
{
	ll ans = 1;
	x = x%p;
	if(x==0)
	return p;

	while(y>0)
	{
		if(y&1)
		{
			ans = (ans*x)%p;
		}
		y = y>>1;
		x = (x*x)%p;
	}
	return ans;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,k,l,m,n;
	cin>>n;
	vi a(n, 0);
	bool ok = false;
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]==1)
	    ok = true;
	}
	if(!ok)
	{
	    cout<<"-1";
	}
	else
	{
	    ll count= 1, sum=0;
	    for(i=0;i<n;i++)
	    {
	        if(a[i]==count)
	        {
	            count++;
	        }
	        else
	        {
	            sum++;
	        }
	    }
	    cout<<sum;
	}
}
