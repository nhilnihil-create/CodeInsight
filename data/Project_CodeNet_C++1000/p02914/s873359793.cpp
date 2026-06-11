#include<bits/stdc++.h>
#define int long long
using namespace std;
int read( ){
	int x=0,y=1;char ch=' ';
	for(;(ch!='-' && (ch>'9' || ch<'0'));ch=getchar( ));
	if(ch=='-')y=-1,ch=getchar( );
	for(;ch>='0' && ch<='9';ch=getchar( ))x=x*10+ch-48;
	return x*y;
}
const int N=1e5+10;
int n,ans,tot;
int a[N],p[110];
void ins(int x){
	for(register int i=62;i>=0;--i){
		if(!(x & (1ll<<i)))continue;
		if(!p[i]){
			p[i]=x;return;
		}
		x^=p[i];
	}
}
signed main( ){
	int x,y,z,k,sum=0;
	n=read( );
	for(register int i=1;i<=n;++i){
		a[i]=read( );
		sum^=a[i];
	}
	for(register int i=1;i<=n;++i)
		a[i]&=~sum;
	
	for(register int i=1;i<=n;++i)ins(a[i]);
	for(register int i=62;i>=0;--i)
		if((ans^p[i])>ans)ans^=p[i];
	printf("%lld\n",ans*2+sum);
	return 0;
}