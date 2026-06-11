#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=1e5+5;
ll cnt[N];
ll n,k,ans;
ll pow(ll num)
{
	ll res=1,m=n;
	while(m>0){
	    if(m&1)
	    res=res*num%mod;
	    num=num*num%mod;
	    m>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>k;
	for(ll i=k;i>=1;i--)
	{
	    cnt[i]=pow(k/i);
	    for(ll j=2;j*i<=k;j++)
		{
	        cnt[i]-=cnt[j*i];
	    }
	    ans+=(mod+(cnt[i]*i)%mod)%mod;
	    ans=(ans+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}