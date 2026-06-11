/* written by : vipin kumar */
#include<iostream>
#include<set>
#include<map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
using namespace std;
#include<vector>
#define int long long int
#define mod 1000000007
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	int j,arr[n];
	for(j=0;j<n;j++)
	{
		cin>>arr[j];
	}
	int answer=0;
	int i;
	for(i=0;i<n;i++)
	{
		int total=0;
		for(j=0;j<n;j++)
		{
			if(arr[j]<arr[i])
			    total++;
		}
		int next=0;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			    next++;
		}
		answer+=(k*next);
		answer%=mod;
		int val=(k*(k-1))/2;
		val%=mod;
		answer+=(total)*(val);
		answer%=mod;
	}
	cout<<answer<<endl;
}

