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

#define int long long
#define x first
#define p second
#define pii pair<int,int>

const int N=2e5+5;
priority_queue<pii> q;
int n,a[N],b[N],ans;

void GG(){
	write(-1);
	exit(0);
}

signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) if(a[i]>b[i]) GG();
	for(int i=1;i<=n;i++) if(b[i]>a[i]) q.push(pii(b[i],i));
	while(!q.empty()){
		int p=q.top().p,x=p-1,y=p+1;q.pop();
		if(!x) x=n;
		if(y>n) y=1;
		if(a[p]>=b[x]&&a[p]>=b[y]){
			if((b[p]-a[p])%(b[x]+b[y])) GG();
			ans+=(b[p]-a[p])/(b[x]+b[y]);
			b[p]=a[p];
			continue;
		}
		if(b[p]<b[x]+b[y]) GG();
		ans+=b[p]/(b[x]+b[y]);
		b[p]%=b[x]+b[y];
		if(a[p]==b[p]) continue;
		if(b[p]<a[p]) GG();
		q.push(pii(b[p],p));
	}
	write(ans);
}