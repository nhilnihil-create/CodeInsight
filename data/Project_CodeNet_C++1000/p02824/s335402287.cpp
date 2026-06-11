#include <algorithm>
#include <cstdio>

typedef long long ll;

inline int read(){
	char c=getchar(); int x=0,ft=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') ft=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*ft;
}

const int N=1e5+5;

int n,m,v,p,a[N]; ll sum[N];

int main(){
	n=read(); m=read(); v=read(); p=read();
	for(int i=1;i<=n;++i) a[i]=read();
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	int ans=n-p;
	while(ans){
		if(a[ans]+m<a[n-p+1]) break;
		if(1ll*(ans+p-1)*m
		 +1ll*(n-ans-p+1)*(a[ans]+m)
		 -(sum[n-p+1]-sum[ans])
		 >=1ll*v*m) --ans;
		else break;
	}
	printf("%d\n",n-ans);
	return 0;
}