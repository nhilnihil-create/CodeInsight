#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<utility>
#include<climits>
#include<set>
using namespace std;
#define ll long long

	    ll mod=1000000007;
ll func(ll a,ll b)
{
	if(b==0)
		return 1LL;

	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b=b>>1;
	}
	return ans;
}
int main(){ 
	ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	    
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif


		ll n;cin>>n;
	    if(n==1)
	    {
	    	cout<<0;
	    	return 0;
	    }


	    
	    ll a=10;
	    ll b=9;
        ll c=8;
        ll d=n;
        
        ll ans1=func(10,n);
        ll ans2=func(9,n);
        ll ans3=func(8,n);


        
        cout<<(ans1%mod - (2*ans2)%mod + ans3%mod +mod)%mod;
}