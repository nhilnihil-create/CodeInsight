#include <bits/stdc++.h>
using namespace std;
typedef  long long  ll;
	int mod=1e9+7;
	ll power(ll n,ll b){
		ll ans=1;
		while(b>0){
			
			if(b&1){
				ans=(ans*n)%mod;
			}
			n=(n*n)%mod;
			b>>=1;
		}

		return ans;
	}

	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	   
	  	int n;
	  	cin>>n;
	  	
	  	ll ans= (power(10,n)-(1LL*2*power(9,n))%mod+power(8,n) +mod)%mod;

	  	cout<<ans<<endl;
	    return 0;
}



