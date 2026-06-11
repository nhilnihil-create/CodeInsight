#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll long long int
 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int a[n];
	int cnt=0;
	for(int i=0;i<n;i++)
	{
	     cin>>a[i];
	     if(a[i]>=k)
	     cnt++;
	}
	cout<<cnt;
	return 0;
}