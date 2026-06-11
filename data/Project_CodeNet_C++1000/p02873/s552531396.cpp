#include<bits/stdc++.h>
typedef long long LL;
typedef double dl;
#define opt operator
#define pb push_back
const LL maxn=1e6+9,mod=998244353;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3ll)+(x<<1ll)+c-'0'; c=getchar();
	}return x*f;
}
void Chkmin(LL &x,LL y){
	if(y<x) x=y;
}
void Chkmax(LL &x,LL y){
	if(y>x) x=y;
}
LL add(LL x,LL y){
	return x+=y,x>=mod?x-mod:x;
}
LL dec(LL x,LL y){
	return x-=y,x<0?x+mod:x;
}
LL mul(LL x,LL y){
	return 1ll*x*y%mod;
}
LL n;
char s[maxn];
int main(){
    scanf(" %s",s+1);
	n=strlen(s+1);
	LL ans(0),nw(0),num(0),pre(0),l(0);
	for(LL i=1;i<=n;++i){
		if(s[i]=='>'){
			if(!l) l=i;
			++num;
		}else{
			if(l){
				if(num<=pre){
			        ans+=(num-1)*num/2;
		        }else{
			        ans+=(num-1)*num/2+(num-pre);
		        }
				l=0;
				num=0;
				nw=0;
			}
			pre=++nw;
			ans+=nw;
		}
	}
	if(l){
		if(num<=pre){
			ans+=(num-1)*num/2;
		}else{
			ans+=(num-1)*num/2+(num-pre);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

