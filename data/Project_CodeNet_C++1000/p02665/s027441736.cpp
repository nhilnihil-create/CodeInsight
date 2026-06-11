#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define F  first
#define S  second
#define ff(i,n) for(i=0;i<n;i++)
ll bg=1000000000000000000;
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
int main()
{ 
	ll t;
	t=1;
	while(t--)
	{
		ll n,i,vertex = 0;
		cin>>n;
		ll a[n+1],b[n+1];
		ff(i,n+1)
		   cin>>a[i];
		b[0] = 1-a[0];
		if(b[0]<0)
		{
			cout<<"-1";
			return 0;	
		}   
		for(i=1;i<=n;i++)
		{
			b[i] = min(bg,2*b[i-1]-a[i]);
			if(b[i]<0)
			{
				cout<<"-1";
				return 0;
			}
		}
		b[n] = 0;
		for(i=n-1;i>=0;i--)
			b[i]=min(b[i],a[i+1]+b[i+1]);
		for(i=0;i<n;i++)
			vertex+=(a[i]+b[i]);
		vertex+=a[n];
		cout<<vertex;			
	}   
	return 0;
}