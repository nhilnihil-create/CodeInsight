#include<iostream>
#include<algorithm>
using namespace std;
#include<cmath>
#define int long long int
#define mod 1000000007
int32_t main()
{
	int n;
	cin>>n;
	int j,arr[n];
	for(j=0;j<n;j++)
	   cin>>arr[j];
	for(j=0;j<n;j++)
	{
		arr[j]+=1;
	}
	int answer=1;
	int count[n+1]={3};
	count[0]=3;
	for(j=0;j<n;j++)
	{
		int val=arr[j];
		int available=count[val-1]-count[val];
		answer*=available;
		count[val]++;
		answer%=mod;
	}
	cout<<answer<<endl;
}
