#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll m=1000000007;

int main()
{
	fast;
	int n;cin>>n;
	int k;cin>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll sum=0;
	for(int i=0;i<k;i++)
		sum+=a[i];
	cout<<sum<<nl;
}