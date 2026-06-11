#include <bits/stdc++.h>
#include <string.h>
#define ll long long
using namespace std;
struct value
{
	ll x;
	ll y;
};
bool compare(value a, value b)
{
	//for descending order replace with a.roll >b.roll
	if (a.y < b.y)
		return 1;
	else
		return 0;
}
ll sum(ll n)
{
	ll c;
	ll sum1=0;
	while(n>0)
	{
		c=n%10;
		sum1=sum1+c;
		n=n/10;
	} return sum1;
}
ll minm(ll arr[],ll n)
{
	ll mi=arr[0];
	for(ll i=0;i<n;i++)
	{ 
		if(mi>arr[i])
	     mi=arr[i];
	}
	return mi;
}
ll maxm(ll arr[],ll n)
{
	ll ma=arr[0];
	for(ll i=0;i<n;i++)
	{ 
	if(ma<arr[i])
	     ma=arr[i];
	}
	return ma;
}
ll pos(ll arr[],ll n)
{
	ll o=maxm(arr,n);
	ll po;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]==o)
		   po=i;
	}return po;
}
void pk()
{
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	ll sum=0;
	if(k<=a)
	   {cout<<k; return;}
	sum=sum+a;
	k=k-a;
	if(k<=0)
	{
		cout<<sum;
		return;
	}
	k=k-b;
	if(k<=0)
	{
		cout<<sum;
		return;
	}
	sum=sum-min(k,c);
	cout<<sum;

	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ll t;
	// cin>>t;
	// while(t--)
	// {
		pk();
	//}
	
}