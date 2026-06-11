#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long qpow(long long a,long long b) {
	long long ans=1;
	while(b>0) {
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long N,K,ans=0;
	cin>>N>>K;
	vector<long long>sum(K+1);
	for(int i=K;i>0;i--) {
		sum[i]=qpow(K/i,N);
		for(int j=2*i;j<=K;j+=i) sum[i]=(sum[i]-sum[j]+mod)%mod;
		ans=(ans+sum[i]*i%mod)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
