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
int n,k,a[N];
ll f[N][N];

int main()
{
	n=read();k=read();
	rep(i,1,n)a[i]=read(),f[i][1]=a[i];
	rep(i,1,n){
		rep(j,2,n-k){
			f[i][j]=inf;
			rep(l,1,i-1){
				f[i][j]=min(f[i][j],f[l][j-1]+max(0,a[i]-a[l]));
			}
		}
	}ll ans=inf;
	rep(i,1,n)ans=min(ans,f[i][n-k]);
	printf("%lld\n",ans);
	return 0; 
}