#include <iostream>
#define ll long long
const int K=1e5+5;
const int mod=1e9+7;
using namespace std;
ll dp[K];
ll quick_pow(ll x,ll y){
	ll res=1;
	while(y){
		if(y%2==1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
int main(){
	ll n,k; cin>>n>>k;
	for(int i=k;i>=1;i--){
		dp[i]=quick_pow(k/i,n);
		for(int j=2*i;j<=k;j+=i) dp[i]-=dp[j];
	}
	ll ans=0;
	for(int i=1;i<=k;i++)
		ans=(ans+(dp[i]*i)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
