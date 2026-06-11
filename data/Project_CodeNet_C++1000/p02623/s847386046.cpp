//Practice more and more
//learn for better
#define bn begin()
#define en end()
#define mx 5000010
#define pb push_back
#define PI (2.0*acos(0.0))
#define ALL(a) a.begin(),a.end()
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rep(a,b) for(int a=0;a<b;++a)
#define fastio ios::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int>  vi;
typedef vector<ll>   vll;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
vll v1,v2;
v1.pb(0),v2.pb(0);
	ll a,b,n,m,i,t,tmp,k;
	cin>>n>>m>>k;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		v1.pb(sum);
	}
	sum=0;
for(i=0;i<m;i++)
{
	cin>>a;
	sum+=a;
	v2.pb(sum);
}
ll cnt=0;
for(i=0;i<=n;i++)
{
	ll low=0,high=m,mid;
	while(1)
	{
		if(low>high)
		break;
	mid=low+(high-low)/2;
	if(v1[i]+v2[mid]<=k)
	{
		if(cnt<mid+i)
		{
			cnt=mid+i;
		}
			low=mid+1;
	}
	else
	{
		high=mid-1;
		}	
	}
}
cout<<cnt<<endl;
	return 0;
}