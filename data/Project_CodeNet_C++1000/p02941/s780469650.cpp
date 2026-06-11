#include <bits/stdc++.h>
#define N 200010
#define int long long
#define lson l,mid,o<<1
#define rson mid+1,r,o<<1|1
#define Ls(o) t[o].ls
#define Rs(o) t[o].rs
#define For(i,x,y) for(int i=(x);i<=(y);++i)
#define Rof(i,x,y) for(int i=(x);i>=(y);--i)
#define mcpy(x,y) memcpy(x,y,sizeof(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define pii pair<int,int>
#define mp make_pair 
#define fr first
#define sd second 
using namespace std;
int a[N],b[N];
priority_queue< pii > q;
main(){
	int n,ans=0;
	scanf("%d",&n);
	For(i,0,n-1) scanf("%lld",&a[i]);
	For(i,0,n-1) scanf("%lld",&b[i]),q.push(mp(b[i],i));
	while(!q.empty()){
		pii x=q.top();q.pop();
		if(b[x.sd]==a[x.sd]) continue;
		int tmp=b[(x.sd+1)%n]+b[(x.sd-1+n)%n];
		if(b[x.sd]-tmp<a[x.sd]) return puts("-1"),0;
		ans+=(b[x.sd]-a[x.sd])/tmp;
		b[x.sd]-=1ll*(b[x.sd]-a[x.sd])/tmp*tmp;
		if(b[x.sd]!=a[x.sd]) q.push(mp(b[x.sd],x.sd));
	} printf("%lld\n",ans);
}
