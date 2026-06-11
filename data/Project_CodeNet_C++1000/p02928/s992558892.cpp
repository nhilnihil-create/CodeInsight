#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020
const int mod=1e9+7;
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
int n,a[N],k,cnt0,cnt1;
int S2(int n){
	return 1LL*n*(n+1)/2%mod;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cnt0+=(a[i]<a[j]);
			cnt1+=(a[i]>a[j]);
		}
	}
	printf("%lld\n",(1LL*cnt0*S2(k-1)+1LL*cnt1*S2(k))%mod);
	return 0;
}
