#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

ll divisors(ll n,bool a)
{
	ll ans = 0,h;
	for(ll i = 2; i<=sqrt(n);i++)
	{
		ll g = n%i;
		if(g==0)
		{
			ans++;
			h = n/i;
			if(h!=i)
				ans++;
			if(a)
			{
				if(h!=i)
					ans--;
				while(h%i==0)
					h/=i;
				if(h!=1 && h%i!=1)
					ans--;
			}
		}
	}
	return (ans+1);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	if(n==2)
	{
		cout<<1<<endl;
		return 0;
	}
	ll h = divisors(n-1,0);
	h += divisors(n,1);
	cout<<h<<endl;
	return 0;
}