#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p=1000000007;
ll bin(ll val,ll po)
{
	if(po==0)
		return 1;
	ll ans=1;
	if(po%2==1)
	{
		po-=1;
		ans=ans*val%p;
	}
	ll p1=bin(val,po/2);
	ans=ans*p1%p;
	ans=ans*p1%p;
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    ll n,k;
	    cin>>n>>k;
	    ll fact[n+1];
	    fact[0]=1;
	    for(ll i=1;i<=n;i++)
	    	fact[i]=fact[i-1]*i%p;
	    ll finv[n+1];
	    finv[0]=1;
	    for(ll i=1;i<=n;i++)
	    {
	    	finv[i]=finv[i-1]*bin(i,p-2)%p;
	    	//cout<<finv[i]<<endl;
	    }
	    for(ll i=1;i<=k;i++)
	    {
	    	if((n-k+1)>=i)
	    	{
	    		ll ans=fact[k-1]*fact[n-k+1]%p;
	    		//cout<<ans<<endl;
	    		ans=ans*finv[i-1]%p;
	    		//cout<<ans<<endl;
	    		ans=ans*finv[k-i]%p;
	    		//cout<<ans<<endl;
	    		ans=ans*finv[n-k+1-i]%p;
	    		//cout<<ans<<endl;
	    		ans=ans*finv[i]%p;
	    		cout<<ans<<endl;
	    	}
	    	else
	    		cout<<"0\n";
	    }
}