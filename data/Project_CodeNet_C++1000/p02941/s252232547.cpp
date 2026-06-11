#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define el putchar('\n')
#define ta putchar('	')
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=200010;
int n,a[N],b[N];
set<pii>st;

inline void no(){puts("-1");exit(0);}

int main()
{
	n=rd();
	fo(i,1,n)a[i]=rd();
	fo(i,1,n)b[i]=rd();
	fo(i,1,n)if(a[i]!=b[i]){
		if(a[i]>b[i])no();
		st.insert(pii(b[i],i));
	}
	ll ans=0;
	while(!st.empty()){
		pii x=*st.rbegin();st.erase(x);
		int pre=x.second-1,now=pre+1,nxt=now+1;
		if(pre<=0)pre+=n;
		if(nxt>n)nxt-=n;
		int hh=max(a[now],b[pre]+b[nxt]);
		int step=(b[now]-hh)/(b[pre]+b[nxt]);
		ans+=step;b[now]-=step*(b[pre]+b[nxt]);
		if(b[now]==a[now])continue;
		b[now]-=b[pre]+b[nxt];++ans;
		if(b[now]==a[now])continue;
		if(b[now]>a[now]){
			st.insert(pii(b[now],now));
			continue;
		}
		no();
	}
	printf("%lld\n",ans);
	return 0;
}
