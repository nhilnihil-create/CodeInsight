#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;

ll dp[100003];
ll k,n;
ll bp(ll x){
	ll s=x;
	ll t=1ll;
	for(int i=0;i<20;i++){
		if(n&(1<<i)) t=(t*s)%mod;
		s=(s*s)%mod;
	}
	return t;
}

int main () {
	cin>>n>>k;
	ll sol=0ll;
	for(ll i=k;i>0;i--){
		ll bz=k/i;
		dp[i]=bp(k/i);
		for(ll j=2*i;j<=k;j+=i){
			dp[i]=(dp[i]-dp[j]+mod)%mod;
		}
		sol=(sol+dp[i]*i)%mod;
	}
	cout<<sol<<endl;
	



return 0;
}

