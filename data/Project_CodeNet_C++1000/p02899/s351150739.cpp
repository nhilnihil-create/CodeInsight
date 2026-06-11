#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	int n;cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}