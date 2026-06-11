#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll arr[n];
	for(auto& i:arr)
	cin>>i;
	sort(arr,arr+n,greater<ll>());
	ll ans=0;
	int id=0;
	for(int i=0;i<n-1;i++)
	{
		ans+=(ll)arr[id];
		if(i%2==0)
		id++;
	}
	cout<<ans<<endl;
}
	
