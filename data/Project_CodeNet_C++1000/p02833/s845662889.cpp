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
	int t;
	ll n,i,j,k;
	cin>>n;
	if(n%2==1)
	{
	    cout<<0;
	}
	else
	{
	    ll sum = 0;
	    ll temp = 10;
	    while(true)
	    {
	        if(temp>n)
	        break;
	        
	        sum+=(n/temp);
	        temp*=5;
	    }
	    cout<<sum;
	}
	return 0;
}
