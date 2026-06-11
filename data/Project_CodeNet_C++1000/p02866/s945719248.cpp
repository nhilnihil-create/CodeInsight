#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int mod=998244353,N=1e6+5;
int ans=1,cnt[N],d[N],ma,n;

void GG(){
	write(0);
	exit(0);
}

signed main(){
	read(n);
	for(int i=1;i<=n;i++) ma=max(ma,read(d[i])),cnt[d[i]]++;
	for(int i=2;i<=n;i++) if(!d[i]) GG();
	for(int i=0;i<=ma;i++) if(!cnt[i]) GG();
	for(int i=1;i<=ma;i++) for(int j=1;j<=cnt[i];j++) ans=1ll*ans*cnt[i-1]%mod; 
	write(ans);
}