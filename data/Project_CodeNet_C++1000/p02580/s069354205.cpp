#include<bits/stdc++.h>
#define poi 601000
using namespace std;
typedef long long ll;
struct girl
{
	int x,y;
	bool operator<(const girl &b)const
	{
		return (x^b.x)?x<b.x:y<b.y; 
	}
}a[poi];
int b[poi],ans,h,w,n,tans;
set<pair<int,int> > s;
inline int re()
{
	char x=getchar();
	int k=1,y=0;
	while(x<'0'||x>'9')
	{if(x=='-') k=-1;x=getchar();}
	while(x>='0'&&x<='9')
	{y=(y<<3)+(y<<1)+x-'0';x=getchar();}
	return y*k;
}
void wr(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int lookfor(int st)
{
	int x=a[st].x;
	for(int i=st;;i++)
	{
		if(a[i].x!=x) break;
		s.erase(make_pair(b[a[i].y]--,a[i].y));
		s.insert(make_pair(b[a[i].y],a[i].y));
	}
	ans=(*--s.end()).first;
	for(int i=st;;i++)
	{
		if(a[i].x!=x) return i;ans++;
		s.erase(make_pair(b[a[i].y]++,a[i].y));
		s.insert(make_pair(b[a[i].y],a[i].y));
	}
}
signed main()
{
	//freopen("lca.in","r",stdin);
	//freopen("lca.out","w",stdout);
	h=re(),w=re(),n=re();
	for(int i=1;i<=n;i++)
	{
		a[i].x=re(),a[i].y=re();
		b[a[i].y]++;
	}
	for(int i=1;i<=w;i++)
	s.insert(make_pair(b[a[i].y],a[i].y));
	sort(a+1,a+n+1);
	for(int i=1;i<=n;)
	{
		i=lookfor(i);
		tans=max(ans,tans);
	}
	wr(tans);
	return 0;
}