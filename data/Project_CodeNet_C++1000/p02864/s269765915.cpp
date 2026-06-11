#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define fi first
#define se second
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
inline ll readll(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=305;
const ll inf=1e18;
int n,k,a[N],a2[N],m,id[N],id2[N];
ll f[N][N],c[N][N],c2[N][N];

inline void upd(ri i,ri x,ll y){for(;x<=m;x+=x&(-x))c[x][i]=min(c[x][i],y);}
inline void upd2(ri i,ri x,ll y){for(;x<=m;x+=x&(-x))c2[x][i]=min(c2[x][i],y);}
inline ll qry(ri i,ri x){ll y=inf;for(;x;x-=x&(-x))y=min(y,c[x][i]);return y;}
inline ll qry2(ri i,ri x){ll y=inf;for(;x;x-=x&(-x))y=min(y,c2[x][i]);return y;}

inline void init(){
	rep(i,0,m)rep(j,0,n)c[i][j]=c2[i][j]=inf;
}

int main()
{
	n=read();k=read();
	rep(i,1,n)a[i]=read(),a2[i]=a[i];
	sort(a2+1,a2+n+1);m=unique(a2+1,a2+n+1)-a2-1;
	rep(i,1,n)id[i]=lower_bound(a2+1,a2+m+1,a[i])-a2,id2[i]=m+1-id[i];
	init();
	rep(i,1,n){
		REP(j,n-k,2){
			f[i][j]=min(qry(j-1,id[i])+a[i],qry2(j-1,id2[i]));
			upd(j,id[i],f[i][j]-a[i]);
			upd2(j,id2[i],f[i][j]);
		}
		f[i][1]=a[i],upd(1,id[i],f[i][1]-a[i]),upd2(1,id2[i],f[i][1]);
	}ll ans=inf;
	rep(i,1,n)ans=min(ans,f[i][n-k]);
	printf("%lld\n",ans);
	return 0; 
}