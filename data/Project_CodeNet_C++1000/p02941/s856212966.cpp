#include <bits/stdc++.h>
#define int long long
#define m_k make_pair
using namespace std;
const int N=2*1e5+100;
int n,a[N],b[N],vi[N],ans;
queue <pair<int,int> > q;
inline int pre(int x){return((x==1)?n:x-1);}
inline int suc(int x){return((x==n)?1:x+1);}
inline bool check(int x){return(b[x]>=b[pre(x)]+b[suc(x)]&&b[x]>a[x]);}
signed main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	bool bl=1;
	for (int i=1;i<=n;i++) if (b[i]<a[i]) bl=0;
	if (!bl)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (check(i))
		{
			vi[i]=1;
			q.push(m_k(b[i],i));
		}
	}
	bl=1;
	while (!q.empty())
	{
		int x=q.front().second;
		q.pop();
		vi[x]=0;
		int delta=b[x]-a[x];
		delta/=b[pre(x)]+b[suc(x)];
		ans+=delta;
		b[x]-=(b[pre(x)]+b[suc(x)])*delta;
		if (delta==0)
		{
			bl=0;
			break;
		}
		if (check(pre(x)) && !vi[pre(x)]) vi[pre(x)]=1,q.push(m_k(b[pre(x)],pre(x)));
		if (check(suc(x)) && !vi[suc(x)]) vi[suc(x)]=1,q.push(m_k(b[suc(x)],suc(x)));
	}
	if (!bl)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) bl=0;
	if (!bl)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",ans);
}