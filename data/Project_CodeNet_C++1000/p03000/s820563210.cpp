#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,x,cnt=0;
	cin>>n>>x;
	vector <ll> v;
	v.push_back(0);
	ll arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		v.push_back(arr[i]+v[i]);
	}
	for(int i=0;i<v.size();i++)
		if(v[i]<=x)
			cnt++;
	cout<<cnt;
	return 0;
}
