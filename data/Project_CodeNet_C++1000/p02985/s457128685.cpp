#include<bits/stdc++.h>
using namespace std;
#define rg register
#define rep(i,a,b) for (rg int i=(a);i<=(b);i++)
#define per(i,a,b) for (rg int i=(b);i>=(a);i--)
#define pb push_back
#define lowbit(x) (x&(-x))
#define replow(i,a,b) for(rg int i = (a);i<=(b);i+=lowbit(i))
#define perlow(i,a,b) for(rg int i = (b);i>=(a);i-=lowbit(i))
#define mk make_pair
#define VI vector<int>
#define pii pair<int,int>
#define pLL pair<long long,long long>
#define fi first
#define se second
#define il inline
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define inf 0x3f3f3f3f
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
char buf[1<<15],*p1 = buf,*p2 = buf;
inline ll read(){
    #define num ch-'0'
    char ch;bool flag=0;ll res;
    while(!isdigit(ch=getc()))
    (ch=='-')&&(flag=true);
    for(res=num;isdigit(ch=getc());res=res*10ll+num);
    (flag)&&(res=-res);
    #undef num
    return res;
}
inline void write(ll x){
	if (x < 0) x = ~x + 1ll, putchar('-');
	if (x > 9) write(x / 10ll);
	putchar(x % 10ll + '0');
}
#define mid ((l + r)>>1)
#define ls (x<<1)
#define rs ((x<<1)|1)
#undef mid
#undef ls
#undef rs
#define maxn 1010000
const ll mod = 1e9 + 7;
ll fac[maxn],inv[maxn];
ll fpow(ll a,ll v)
{
	ll ans = 1;
	while(v)
	{
		if(v & 1) ans = a * ans % mod;
		v>>=1;
		a = a * a % mod;
	}
	return ans;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=fpow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
 
ll C(ll a,ll b)
{
    if(b>a) return 0;
    return fac[a]*inv[a-b]%mod;
}
struct node{
	int to,nxt;
};
node edge[maxn<<1];
int cnt = 0;
int head[maxn];
void add(int x,int y)
{
	edge[++cnt].to = y;
	edge[cnt].nxt = head[x];
	head[x] = cnt;
}
void addedge(int x,int y)
{
	add(y,x);
	add(x,y);
}
ll dep[maxn];
ll deg[maxn];
void dfs(int x,int fa)
{
	dep[x] = dep[fa] + 1;
	for(int i = head[x];i;i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(v == fa) continue;
		deg[x]++;
		dfs(v,x);
	}
}
void solve()
{
	int n = read(),m = read();
	rep(i,1,n-1)
	{
		int x = read(),y = read();
		addedge(x,y);
	}
	dfs(1,-1);
	ll ans = m;
	rep(i,1,n)
	{
		if(dep[i] == 1) ans = ans * C(m-1,deg[i]);
		else ans = ans * C(m-2,deg[i]);
		ans %= mod;
	}
	printf("%lld\n",ans);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
	#endif
	init();
//	int T = read();
//	while(T--)
	solve();
}