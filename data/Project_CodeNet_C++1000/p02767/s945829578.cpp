#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = acos(-1) ;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"


int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0;
	cin>>n;
	int arr[n];
	tc=n;
	while(tc--)
	{
		cin>>arr[x];
		sum+=arr[x++];
	}
	x=sum/n;
	for(ll i=0;i<n;i++)
	{
		z+=abs(arr[i]-x)*abs(arr[i]-x);
	}
	x++;
	for(ll i=0;i<n;i++)
	{
		ans+=abs(arr[i]-x)*abs(arr[i]-x);
	}
	ans=min(ans,z);
	cout<<ans;
}
