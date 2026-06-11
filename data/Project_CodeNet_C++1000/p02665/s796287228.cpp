#include<bits/stdc++.h>
typedef long long LL;
const LL maxn=1e6+9,up=(1ll<<60ll);
LL n,ans;
LL a[maxn],lg[maxn],g[maxn];
int main(){
	scanf("%lld",&n);
	for(LL i=0;i<=n;++i){
		scanf("%lld",a+i);
	}
	LL flag(1);
	g[0]=1-a[0];
	for(LL i=1;i<=n;++i){
		g[i]=(g[i-1]<<1ll);
		g[i]=std::min(g[i],up);
		if(g[i]<a[i]){
			flag=0;
		}else g[i]-=a[i];
	}
	if(!flag || (!n && a[0]>1)){
		puts("-1");
		return 0;
	}else if(!n){
		printf("%lld\n",a[0]);
		return 0;
	}
	//lg[0]=1; for(LL i=1;i<=50;++i) lg[i]=(lg[i-1]<<1ll);
	LL nw=0;
	//for(LL i=0;i<=n;++i) printf("%lld ",g[i]); puts("");
	for(LL i=n;i>=0;--i){
			if(nw>g[i]) nw=g[i];
		nw+=a[i];
		ans+=nw;
		//printf(" #%lld\n",nw);
	}
	printf("%lld\n",ans);
}