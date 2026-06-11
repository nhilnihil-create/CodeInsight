#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=1e5+10;
const ll MOD=1e9+7;
int n;
ll k;
ll ans[maxN];
ll res=0LL;
ll fast_mi(ll a,int p)
{
	if(p==0)return 1LL;
	ll tmp=fast_mi(a,p>>1);
	tmp=tmp*tmp%MOD;
	if(p&1)
	{
		tmp=tmp*a%MOD;
	}
	return tmp;
}
int main()
{
	cin>>n>>k;
	for(ll x=k;x>=1LL;x--)
	{
		ll multi_num=k/x;
		ll num=fast_mi(multi_num,n);
		for(int i=x+x;i<=k;i+=x)
		{
			num=(num-ans[i]+MOD)%MOD;
		}
		ans[x]=num;
		res=(res+num*x)%MOD;
	}
	cout<<res<<endl;
	return 0;
}
