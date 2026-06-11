#include<bits/stdc++.h>
#define ll  long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define inf 10000000LL
#define fast_io	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
#define range 100001
#define lg 22
using namespace std;

int main()
{
	ll n,x=0;
	cin>>n;
	ll A[n+1];
	ll ans[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>A[i];
		x^=A[i];
	}
	
	for(ll i=1;i<=n;i++)
	{
		ans[i]=x^A[i];
	}
	
	for(ll i=1;i<=n;i++)
	cout<<ans[i]<<" ";

}