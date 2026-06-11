#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,d[N],cnt[N],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
		++cnt[d[i]];
	}
	if(d[1]||cnt[0]^1)return !printf("0\n");
	ans=1;
	for(int i=1;i<n;++i){
		ans=1LL*ans*qpow(cnt[i-1],cnt[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
