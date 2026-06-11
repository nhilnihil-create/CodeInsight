#include<set>
#include<map>
#include<cmath>
#include<deque>
#include<stack>
#include<ctime>
#include<queue>
#include<vector>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;
LL read(){
	LL f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 200000
#define INF 0x3f3f3f3f
LL a[MAXN+5],b[MAXN+5];
int pre[MAXN+5],nxt[MAXN+5];
priority_queue<pair<LL,int> > Q;
int main(){
	//freopen("hopeless.in","r",stdin);
	//freopen("hopeless.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read(),Q.push(make_pair(b[i],i));
	for(int i=1;i<=n;i++)
		pre[i]=i-1,nxt[i]=i+1;
	pre[1]=n,nxt[n]=1;
	LL ans=0;
	while(!Q.empty()){
		int u=Q.top().second;Q.pop();
		if(a[u]==b[u]) continue;
		if(b[u]<b[pre[u]]+a[u]+b[nxt[u]]){
			puts("-1");
			return 0;
		}
		ans+=(b[u]-a[u])/(b[pre[u]]+b[nxt[u]]);
		b[u]=(b[u]-a[u])%(b[pre[u]]+b[nxt[u]])+a[u];
		Q.push(make_pair(b[u],u));
	}
	printf("%lld\n",ans);
	return 0;
}