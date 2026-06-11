#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,l,flag=0,sum=0,min=INT_MAX;
	cin>>n>>l;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=l+i;
		sum+=arr[i];
		if(arr[i]==0)
			flag=1;
	}
	if(flag==1)
	{
		cout<<sum;
		return 0;
	}
	for(int i=0;i<n;i++)
		if(abs(arr[i])<abs(min))
			min=arr[i];
	cout<<sum-min;
	return 0;
}
