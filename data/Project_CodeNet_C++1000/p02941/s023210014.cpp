#include<cstdio>
#include<queue>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,a[N],b[N],pre[N],nxt[N]; long long ans; queue <int> q; bool vis[N];
inline bool check(CI id)
{
	return b[id]-a[id]>=b[pre[id]]+b[nxt[id]];
}
int main()
{
	RI i; for (scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&a[i]);
	for (i=1;i<=n;++i) scanf("%d",&b[i]),pre[i]=i-1,nxt[i]=i+1;
	for (nxt[pre[1]=n]=i=1;i<=n;++i) if (check(i)) q.push(i),vis[i]=1;
	while (!q.empty())
	{
		int nw=q.front(); vis[nw]=0; q.pop();
		int cur=(b[nw]-a[nw])/(b[pre[nw]]+b[nxt[nw]]);
		ans+=cur; b[nw]-=cur*(b[pre[nw]]+b[nxt[nw]]);
		if (!vis[pre[nw]]&&check(pre[nw])) q.push(pre[nw]),vis[pre[nw]]=1;
		if (!vis[nxt[nw]]&&check(nxt[nw])) q.push(nxt[nw]),vis[nxt[nw]]=1;
	}
	for (i=1;i<=n;++i) if (a[i]!=b[i]) return puts("-1"),0;
	return printf("%lld",ans),0;
}