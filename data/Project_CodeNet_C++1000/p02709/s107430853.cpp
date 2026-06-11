#include<bits/stdc++.h>
typedef long long LL;
const LL maxn=2e3+9;
LL n;
LL a[maxn],pos[maxn],f[maxn][maxn];
bool cmp(LL x,LL y){
	return a[x]>a[y];
}
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i) scanf("%lld",a+i);
	for(LL i=1;i<=n;++i) pos[i]=i;
	std::sort(pos+1,pos+1+n,cmp);
	f[0][0]=0;
	for(LL i=1;i<=n;++i){
		LL x(pos[i]);
		for(LL j=0;j<=i;++j){
			if(j) f[i][j]=f[i-1][j-1]+a[x]*std::abs(x-j);
			if(j!=i) f[i][j]=std::max(f[i][j],f[i-1][j]+a[x]*std::abs(x-(n-(i-1-j))));
		}
	}
	LL ans(0);
	for(LL i=0;i<=n;++i){
		ans=std::max(ans,f[n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}