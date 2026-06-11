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
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans;

	cin>>tc;
	n=tc;
	int arr[n];
	for(ll i=0;i<tc;i++)
	{
		cin>>arr[i];
		
	}
	z=1e12;
	for(ll i=1;i<=100;i++)
	{
		sum=0;
		for(ll j=0;j<tc;j++)sum+=abs(arr[j]-i)*abs(arr[j]-i);
		z=min(z,sum);
	}
	cout<<z<<nw;

}
