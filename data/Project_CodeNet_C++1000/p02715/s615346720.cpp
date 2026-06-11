#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=1e5+10;
const ll MOD=1e9+7;
ll n,k;
ll ans[maxN];
ll res=0LL;
ll fast_mi(ll a,ll n)
{
	ll ans=1;
	while(n){
		if(n%2==1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		n=n/2;
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	for(ll x=k;x>=1LL;x--)
	{
		//ll multi_num=k/x;
		 ans[x]=fast_mi(k/x,n);
		for(ll i=2*x;i<=k;i+=x)
		{
			ans[x]=(ans[x]-ans[i])%MOD;  //防止为负数 
		}
		res=(res+ans[x]*x%MOD+MOD)%MOD;
	}
	cout<<res<<endl;
	return 0;
}
