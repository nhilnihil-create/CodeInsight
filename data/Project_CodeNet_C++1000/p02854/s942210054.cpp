#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020 
typedef long long ll;
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
int n,a[N];
ll ans,sum,now;
inline ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	ans=2e18;
	for(int i=1;i<n;++i){
		now+=a[i];
		ans=min(ans,Abs(sum-now-now));
	}
	printf("%lld\n",ans);
	return 0;
}

