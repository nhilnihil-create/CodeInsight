#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll long long 
 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	     cin>>a[i];
	}
	ll tot=0;
	for(int i=0;i<n-1;i++)
	{
	     for(int j=i+1;j<n;j++)
	     {
	          tot+=a[i]*a[j];
	     }
	}
	cout<<tot;

	return 0;
}