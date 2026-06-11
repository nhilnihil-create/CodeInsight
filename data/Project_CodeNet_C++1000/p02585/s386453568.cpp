#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
#define X first
#define Y second
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=5010;
const LL oo=1ll<<60;
int n,K,p[maxn],cnt;
LL c[maxn],ans=-oo,now_ans;
bool vis[maxn];
vector<LL> V;
int main()
{
    n=read();K=read();
    for(int i=1;i<=n;i++)p[i]=read();
    for(int i=1;i<=n;i++)c[i]=read();
    for(int i=1;i<=n;i++)
    {
    	int now=i;
    	LL pre=c[now];
    	V.clear();
    	V.push_back(pre);
    	now=p[now];
    	while(now!=i)pre+=c[now],V.push_back(pre),now=p[now];
    	int sz=V.size();
		for(int j=0;j<sz && K-(j+1)>=0;j++)
            ans=max(ans,V[j]+((K-(j+1))/sz)*max(pre,0LL));
    }
    printf("%lld\n",ans);
    return 0;
}
/*
*/