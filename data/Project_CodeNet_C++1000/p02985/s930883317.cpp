#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<ctime>

#define int long long
#define R register
#define IL inline
#define Rf(a,b,c) for(R int (a)=(b);(a)<=(c);++(a))
#define Tf(a,b,c) for(R int (a)=(b);(a)>=(c);--(a))
#define MP make_pair
#define PA pair<int,int>
#define MES(a,b) memset((a),(b),sizeof((a)))
#define MEC(a,b) memcpy((a),(b),sizeof((b)))
#define D double

using namespace std;

const int N=1e5+5,mod=1e9+7;

int n,k,head[N],tot,dep[N],s[N],fac[N],fa[N],vis[N],vis2[N],ans,son[N];
struct Edge {
	int to,next;
}e[N<<1];

struct node {
	int num,dep;
}tmp;
queue <int> q;
queue <node> q2;

IL int read() {
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x*=10;x+=(ch-'0');ch=getchar();}
    return x*f;
}
IL void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
IL void add(int u,int v) {
	e[++tot].next=head[u];
	e[tot].to=v;head[u]=tot;
}
/*IL int qpow(int x,int y) {
	R int S=1;
	while(y) {
		if(y&1) S=S*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return S;
}
IL int C(int a,int b) {//a>b;
	R int inv1=qpow(fac[b],mod-2),inv2=qpow(fac[a-b],mod-2);
	return fac[a]*inv1%mod*inv2%mod;
}*/
void dfs(int x) {
	for(R int i=head[x];i;i=e[i].next) {
		R int v=e[i].to;
		if(v==fa[x]) continue;
		son[v]--;
		fa[v]=x;dep[v]=dep[x]+1;
		dfs(v);
		s[x]+=son[v]+1;
	}
}
IL int bfs(int now) {
	MES(vis2,0);R int cnt=0;
	tmp.num=now,tmp.dep=0;
	q2.push(tmp);vis2[now]=1;
	while(!q2.empty()) {
		tmp=q2.front();q2.pop();
		R int x=tmp.num,de=tmp.dep;
		for(R int i=head[x];i;i=e[i].next) {
			R int v=e[i].to;
			if(vis[v]&&de<2&&!vis2[v]) {
				cnt++;vis2[v]=1;
				tmp.num=v;tmp.dep=de+1;
				q2.push(tmp);
			}
		}
	}
	return cnt;
}

signed main()
{
	n=read(),k=read();
	Rf(i,2,n) {
		R int u=read(),v=read();
		add(u,v);add(v,u);
	}
	q.push(1);ans=1;
	while(!q.empty()) {
		R int x=q.front();q.pop();vis[x]=1;son[fa[x]]++;
		R int sum=0;
		if(fa[fa[x]]) sum++;
		if(fa[x]) sum+=son[fa[x]];
		ans=ans*(k-sum)%mod;
		for(R int i=head[x];i;i=e[i].next) {
			R int v=e[i].to;
			if(!vis[v]) {
				fa[v]=x;
				q.push(v);
			}
		}
	}
	write(ans);
	
    return 0;
}
