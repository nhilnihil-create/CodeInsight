#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll m,N;
	cin>>N>>m;
	ll arr[N+1];
	for(ll i=0;i<=N;i++)
		arr[i]=1;
	for(ll i =0;i<m;i++)
	{
		ll x;
		cin>>x;
		arr[x]=0;

	}
	ll steps[N+1];
	for(ll i=0;i<=N+1;i++)
	{
		steps[i]=0;
	}
	steps[N]=1;
	for(ll i=N-1;i>=0;i--)
	{
		if(arr[i+1])
			steps[i]=(steps[i]+steps[i+1])%(1000000007);
		if(arr[i+2])
			steps[i]=(steps[i]+steps[i+2])%(1000000007);
	}
	cout<<steps[0]<<"\n";

}