#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(z) (z).begin(),(z).end() 
#define MOD 1000000007
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll isprime(ll n)
{
	for(int i=2;i<n;i++)
		if(n%i==0)
		return 0;
		
	return 1;	
}
int main()
{ 
    FAST;
	ll x;
	cin>>x;
	ll ans=0;
	while(x>=500)
	{
		ans+=1000;
		x-=500;
	}
	while(x>=5)
	{
		ans+=5;
		x-=5;
	}
	cout<<ans;
}
