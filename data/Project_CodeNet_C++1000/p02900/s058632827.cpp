#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	ll a,b;cin>>a>>b;
	vector<ll>v;
	if(a%2==0 && b%2==0)
	{
		v.push_back(2);
		while(a%2==0)
		{
			a=a/2;
		}
		while(b%2==0)
		{
			b=b/2;
		}

	}
	else
	{
		if(a%2==0)
		{
			a=a/2;
		}
		if(b%2==0)
		{
			b=b/2;
		}
	}
	//cout<<b<<nl;
	ll limit=(sqrt(a),sqrt(b));
	for(int i=3;i<=limit+1;i+=2)
	{
		if(a%i==0 && b%i==0)
		{
			v.push_back(i);
			while(a%i==0)
			{
				a=a/i;
			}
			while(b%i==0)
			{
				b=b/i;
			}
		}
		else
		{
			while(a%i==0)
			{
				a=a/i;
			}
			while(b%i==0)
			{
				b=b/i;
			}
		}
	}
	if(a==b && a>1)
		v.push_back(a);
	
	cout<<v.size()+1;
}