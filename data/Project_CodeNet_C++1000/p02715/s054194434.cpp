#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7,N=100010;
ll n,k,ans;
ll gc[N];
ll prime[N];
bool isp[N];
ll expo(ll base,ll ex,ll mod){
	if(ex==0) return 1;
	ll tmp=expo(base,ex>>1,mod);
	tmp=tmp*tmp%mod;
	if(ex&1) return tmp*base%mod;
	return tmp;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=2;i<N;++i) isp[i]=true;
	for(ll i=2;i<N;++i){
		if(isp[i]){
			prime[++prime[0]]=i;
		}
		for(ll j=1;j<=prime[0]&&prime[j]*i<N;++j){
			isp[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
	for(ll g=1;g<=k;++g){
		if(g>1){
			if(k/g==k/(g-1)) gc[g]=gc[g-1];
		}
		gc[g]=expo(k/g,n,M);
	}
	for(ll g=k;g>=1;--g){
		for(ll i=2;i*g<=k;++i){
			gc[g]-=gc[g*i];
			if(gc[g]<0) gc[g]+=M;
		}
	}
	for(ll g=1;g<=k;++g){
		ans+=gc[g]*g%M;
		ans%=M;
	}
	printf("%lld",ans);
}