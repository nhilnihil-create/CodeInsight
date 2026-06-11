#include<bits/stdc++.h>
#define MN 200000
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<pa> q;
int n,a[MN+5],b[MN+5];long long ans;
inline int lst(int x){return x==1?n:x-1;}
inline int nxt(int x){return x==n?1:x+1;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i)
    {
        b[i]=read();
        if(b[i]<a[i]) return 0*puts("-1");
        if(b[i]!=a[i]) q.push(mp(b[i],i));
    }
    while(!q.empty())
    {
        int x=q.top().second;q.pop();
        int per=b[lst(x)]+b[nxt(x)];
        int mx=q.empty()?int(1e9):((b[x]-max(b[lst(x)],b[nxt(x)]))/per+1);
        mx=min(mx,(b[x]-a[x]+per-1)/per);
        b[x]-=mx*per;
        if(b[x]<a[x]) return 0*puts("-1");
        if(b[x]!=a[x]) q.push(mp(b[x],x));
        ans+=mx;
    }
    printf("%lld\n",ans);
    return 0;
}
