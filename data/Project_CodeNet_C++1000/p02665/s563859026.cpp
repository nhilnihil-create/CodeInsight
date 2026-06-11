#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

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
int a[N],b[N],c[N];

signed main()
{
	int n=read()+1;
	for (int i=1;i<=n;i++) a[i]=read();
	b[n]=c[n]=a[n];
	if (n==0)
	{
		if (a[1]==1) puts("1");
				else puts("-1");
		return 0;
	}
	for (int i=n-1;i>=1;i--)
	{
		c[i]=a[i]+(c[i+1]+1)/2;
		b[i]=a[i]+b[i+1];
	}
	if (c[1]>1)
	{
		puts("-1");
		return 0;
	}
	int ans=1,cnt=1;
	for (int i=2;i<=n;i++)
	{
		cnt-=a[i-1];
		cnt=min(cnt*2,b[i]);
		ans+=cnt;
	}
	print(ans);

	return 0;
}