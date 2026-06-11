#include <bits/stdc++.h>
using namespace std;
#define w(x) int x;cin>>x;while(x--)
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define fr(a,b) for(int i=a;i<=b;i++)
#define inf 1e18
#define mod 1000000007

int main()
{   

	fast;
	ll n;
	cin>>n;
	ll a[n+1];
	ll b[n+1];
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[i]=x+y;
		b[i]=x-y;
	}
	sort(a,a+n);
	sort(b,b+n);
	cout<<max(a[n-1]-a[0],b[n-1]-b[0])<<"\n";
	
	return 0;

}
