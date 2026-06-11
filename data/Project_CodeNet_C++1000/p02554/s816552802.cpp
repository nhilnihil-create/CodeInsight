#include <bits/stdc++.h>
#define ll long long
#define pb push_back
ll mod=1000000007;
using namespace std;

ll pow(ll x,ll y,ll mod){
	ll ans=1;
	while(y>0){
		if(y&1){
			ans=ans*x%mod;
		}

		y=y>>1;
		x=x*x%mod;
	}

	return ans%mod;
}

int main(){
	ll n;
	cin>>n;
	//ll x=10,y=9,z=8;
	ll x=pow(10,n,mod);
	ll y=pow(9,n,mod);

	ll z = pow(8,n,mod);
	
	//cout<<x<<" "<<y<<" "<<z<<endl;
	ll ans = 0;
  	
  	ans = ((x-y-y+z)%mod+mod)%mod;
  
	cout<<ans<<endl;
}
