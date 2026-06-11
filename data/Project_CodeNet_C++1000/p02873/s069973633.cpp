#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define F  first
#define S  second
#define ff(i,n) for(i=0;i<n;i++)
ll bg = 1000000007;
ll power(ll x,ll y)
{
	if(y==0)
		return 1;
	ll h=power(x,y/2)%bg;	
	h=(h*h)%bg;
	if(y%2==1)
	  return (x*h)%bg;
	else
	  return h%bg;  
}
ll modinv(ll m)
{
	return power(m,bg-2)%bg;
}
vector<ll> z_func(vector<ll> a)
{
	ll n = a.size();
	vector<ll> z(n);
	ll l=0,r=0;
	for(ll i=1;i<n;i++)
	{
		if(i<=r)
			z[i] = min(r-i+1,z[i-l]);
		else
			z[i]=0;
		while(i+z[i]<n && a[z[i]]==a[i+z[i]])
		   z[i]++;
		if(i+z[i]-1>r)
		{
			l = i;
			r = i+z[i]-1;	
		}   		
	}
	return z;
}
string s;
ll arr[600000];
vector<vector<ll> >adj(600000);
int main()
{ 
	ll t;
	t=1;
	while(t--)
	{
		ll i,n;
		string f;
		cin>>f;
		n = f.length();
		ll a[n+1],b[n+1];
		a[0] = 0;
		ll c = 0;
		for(i=1;i<=n;i++)
		{
			if(f[i-1]=='<')
				c++;
			else
				c = 0;
			a[i]=c;		
		}
		c= 0;
		b[n]=0;
		for(i=n-1;i>=0;i--)
		{
			if(f[i]=='>')
			    c++;
			else
			    c = 0;
			b[i]=c;	    
		}
		ll ans = 0;
		ff(i,n+1)
			ans+=max(a[i],b[i]);
		cout<<ans;	
	}	    
	return 0;
}