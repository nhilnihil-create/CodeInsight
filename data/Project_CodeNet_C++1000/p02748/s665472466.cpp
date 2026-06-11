#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"


int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	ll A,B,M,ac=1e12,ak=ac;
	cin>>A>>B>>M;
	ll a[A+1],b[B+1];
	for(ll i=1;i<=A;i++){
		cin>>a[i];
		ac=min(a[i],ac);
	}
	for(ll i=1;i<=B;i++){
		cin>>b[i];
		ak=min(ak,b[i]);
	}
	ll max=ak+ac;
	while(M--)
	{
		cin>>x>>y>>z;
		k=a[x]+b[y]-z;
		max=min(k,max);
		
	}
	cout<<max;
}
