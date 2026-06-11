#include<bits/stdc++.h>

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef  long long  ll;

int main()
{
  fastIO();


	ll n , m , satf=0;
	cin>>n;
	m = n-1;
	ll arr[n], brr[n],  crr[m];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		arr[i]--;
	}
	for(int i=0; i<n; i++)
	{
		cin>>brr[i];
	}
	for(int i=0; i<m; i++)
	{
		cin>>crr[i];
	}
	for(int i=0; i<n; i++)
	{
		satf += brr[arr[i]];
		if(arr[i]==arr[i-1]+1)
		//then crr-1 from arr;}	
		{
			satf+= crr[arr[i-1]];
			}
	}
	cout<<satf<<'\n';
 return 0;
 }
