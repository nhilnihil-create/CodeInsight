#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n;
ll ans,tot;
int main(){
	n=read();
	ans=-1;
	for(int i=1;i<=n;++i){
		ll d=read(),c=read();
		tot+=d*c;
		ans+=c;
	}
	ans+=(tot-1)/9;
	printf("%lld\n",ans);
	return 0;
}

