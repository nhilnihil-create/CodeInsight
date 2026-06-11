#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[2005];
const int mod=1e9+7;
ll inv(ll b){return b==1?1:(mod-mod/b)*inv(mod%b)%mod;}
ll c(int n,int r){
	if(r==0||r==n)
		return 1;
	if(n<r)
		return 0;
	return fac[n]*inv(fac[r])%mod*inv(fac[n-r])%mod;
}
int main(){
	fac[1]=1;
	fac[0]=1;
	for(int i=2;i<=2000;i++)
		fac[i]=fac[i-1]*i%mod;
	int n,k;
	scanf("%d%d",&n,&k);
	ll ans=1;
	for(int i=1;i<=k;i++){
		ll r,b;
		r=c(n-k+1,i);
		b=c(k-1,i-1);
		ans=r*b%mod;
		printf("%lld\n",ans);
	}
	return 0;
}