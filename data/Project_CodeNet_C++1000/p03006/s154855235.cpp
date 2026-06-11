#include<bits/stdc++.h>
#define x first
#define y second
#define mk make_pair
using namespace std;
const int N=55;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
pair<int,int>a[N];
bool vis[N];

signed main()
{
	int n=read(),ans=n;
	for (int i=1;i<=n;i++)
	{
		a[i].x=read();
		a[i].y=read();
	}
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	if (i!=j)
	{
		int p=a[j].x-a[i].x,q=a[j].y-a[i].y,cnt=0;
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=1;
			cnt++;
			int now=i;
			while (1)
			{
				int nxt=lower_bound(a+now+1,a+n+1,mk(a[now].x+p,a[now].y+q))-a;
				if (a[nxt]==mk(a[now].x+p,a[now].y+q))
				{
					now=nxt;
					vis[nxt]=1;
				}
				else break;
			}
		}
		ans=min(ans,cnt);
	}
	print(ans);

	return 0;
}