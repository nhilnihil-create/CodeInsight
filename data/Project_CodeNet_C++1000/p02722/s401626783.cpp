#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n;
	cin>>n;
	if(n==2){
		cout << 1;
		return 0;
	}
	ll ans=2;
	for(ll i=2;i<=sqrt(n);i++){
		ll mod=i;
		ll now;
			now=n;
			ll mod2=i;
			while(now%mod==0){
				now/=mod;
			}
			if(now%mod==1){
				ans++;
			}
			mod=n/i;
			if(mod2!=mod){
			now=n;
			while(now%mod==0){
					now/=mod;
			}
			if(now%mod==1){
				ans++;
			}			
			}
	}
	cout <<ans;
	// your code goes here
	return 0;
}