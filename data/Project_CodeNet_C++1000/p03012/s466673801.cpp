#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,sum=0,sum1=0,ans=INT_MAX;
	cin>>n;
	ll arr[n];
	for(int i =0;i<n;i++)
		cin>>arr[i],sum+=arr[i];
	for(int i=0;i<n-1;i++)
	{
		sum1+=arr[i];
		if(abs(2*sum1-sum)<ans)
			ans=abs(2*sum1-sum);
	}
	cout<<ans;
	return 0;
}
