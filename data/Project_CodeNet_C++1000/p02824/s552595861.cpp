#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<cmath>
//#include<algorithm>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;
#define PII pair<ll,ll>
typedef long long ll;
const int maxn=1e5+9;
const double pi=acos(-1);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double ep=1e-7;
using namespace std;
ll n,m,v,p,a[maxn]; 
bool check(ll num)
{
	ll b=a[n-p+1];
	if(a[num]>=b)return 1;
	if(a[num]+m<b)return 0;
	if(num+p-1>=v)
	{
		if(a[num]+m>=b)return 1;
		else return 0;
	}
	ll sum=(v-num-p+1)*m;
	for(ll i=num+1;i<=n-p+1;i++)
	{
		sum-=(a[num]+m-a[i]);
	}
	if(sum>0)return 0;
	return 1;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll l=1,r=n,ans;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=n-mid+1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}