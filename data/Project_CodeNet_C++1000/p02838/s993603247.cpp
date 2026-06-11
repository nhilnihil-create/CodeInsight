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
	ll i, j, k, l, m, n;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++) cin>>a[i];
	
	ll sum = 0;
	for(i=0;i<=60;i++)
	{
	    ll one = 1;
	    ll bit = one<<i;
	    ll count1=  0, count0 = 0;
	    for(j=0;j<n;j++)
	    {
	        if(a[j]&bit)
	        {
	           // if(i==32)
	           // cout<<"a:"<<a[j]<<" bit:"<<bit;
	            count1++;
	        }
	        else
	        {
	           // if(i==32)
	           // cout<<"a:"<<a[j]<<" bit:"<<bit;
	            count0++;
	        }
	        
	    }
	    bit = bit%mod;
	    ll bitsum = (count0*count1)%mod;
	    bitsum = (bitsum*bit)%mod;
	    sum = (sum + bitsum)%mod;
	    //cout<<"\ni:"<<i<<" sum:"<<sum<<" bitsum:"<<bitsum;
	}
	cout<<sum<<"\n";
	return 0;
}
