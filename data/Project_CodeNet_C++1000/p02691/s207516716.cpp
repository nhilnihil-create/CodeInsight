#include<iostream>
#include<map>
#define ll long long
using namespace std;
const int maxn=9e5+10;
ll a[maxn]; 
int main()
{
	ll n;
	ll ans=0;
	cin>>n;
	map<ll,ll>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[i-a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=mp[i+a[i]];
	}
	cout<<ans<<endl;
	return 0;
 } 