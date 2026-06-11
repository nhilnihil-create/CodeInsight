#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=2e18;
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
ll ans;
int n,a[N];
ll s[N],res;
int main(){
	n=read();
	for(int i=0;i<=n;++i){
		a[i]=read();
	}
	for(int i=n;i>=0;--i){
		s[i]=s[i+1]+a[i];
	}
	if(!n){
		return !printf("%d\n",a[0]==1?1:-1);
	}
	else if(a[0]){
		return !printf("-1\n");
	}
	res=ans=1;
	for(int i=1;i<=n;++i){
		res=min(inf,(res-a[i-1])<<1);
		if(res<a[i]){
			return !printf("-1\n");
		}
		ans+=min(res,s[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

