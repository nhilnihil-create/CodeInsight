#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mod=1e9+7;
ll f[N];
ll n,k;
ll qpow(ll x,ll y) {
	ll s=1;
	while (y) {
		if (y&1) s=(s*x)%mod;
		x=(x*x)%mod;
		y>>=1;	
	}
	return s;
}
int main() {
	ll i,j,ans=0;
	cin>>n>>k;
	for (i=k;i>=1;i--) {
		f[i]=qpow(k/i,n);
		for (j=i+i;j<=k;j+=i)
			f[i]=(f[i]-f[j]+mod)%mod;
		ans=(ans+f[i]*i%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}