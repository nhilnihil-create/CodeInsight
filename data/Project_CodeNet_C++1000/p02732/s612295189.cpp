#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll num;
	cin>>num;
	vector<ll>arr(num);
	map<int,ll>rel;
	for(int i=0; i<num; i++)
	{
		cin>>arr[i];
		rel[arr[i]]++;
	}
	ll sum=0;
	for(auto var : rel)
	{
		ll n=var.second;
		sum+=n*(n-1)/2;
	}
//	cout<<"sum : "<<sum<<"\n";
	for(int i=0; i<num; i++)
	{
		int temp=arr[i];
		if(rel[arr[i]]<2)
		 cout<<sum<<"\n";
		else
		 cout<<sum-rel[arr[i]]+1<<"\n";
	}
	return 0;
	
}