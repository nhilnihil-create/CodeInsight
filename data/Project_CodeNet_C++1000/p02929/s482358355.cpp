#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[200010],v=1,nw,fac=1;
char c[200010];
int main(){
	scanf("%d%s",&n,c+1),n<<=1;
	for(int i=1;i<=(n>>1);++i)fac=1ll*fac*i%mod;
	for(int i=1;i<=n;++i)a[i]=c[i]=='B';
	nw=0;
	for(int i=1;i<=n;++i){
		if((((nw+1)^a[i])&1)==0)++nw;
		else if(nw)v=1ll*v*nw%mod,--nw;
		else return puts("0"),0;
	}
	if(nw)return puts("0"),0;
	printf("%lld",1ll*v*fac%mod);
	return 0;
}