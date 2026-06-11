#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 2e5+10;
int n,a[N],b[N];
ll c[N];
priority_queue<pair<ll,int>>q;

inline void GG(){
	puts("-1");exit(0);
}
inline int l(int u){
	return u==1?n:u-1;
}
inline int r(int u){
	return u==n?1:u+1;
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=c[i]=read();
	For(i,1,n) if (a[i]!=b[i]) q.push(mp(b[i],i));
	ll ans=0;
	while (!q.empty()){
		int u=q.top().se;q.pop();
		if (q.empty()){
			ll tmp=c[u==n?1:u+1]+c[u==1?n:u-1];
			if ((c[u]-a[u])%tmp) GG();
			ans+=(c[u]-a[u])/tmp;break;
		}
		int v=l(u);
		if (c[r(u)]>c[v]) v=r(u);
		ll tmp=c[r(u)]+c[l(u)],x=(c[u]-max(c[v],(ll)a[u]))/tmp;
		x=max(x,1ll);
		c[u]=c[u]-x*tmp,ans+=x;
		if (c[u]<a[u]) GG();
		if (c[u]>a[u]) q.push(mp(c[u],u));
	}
	printf("%lld\n",ans);
}