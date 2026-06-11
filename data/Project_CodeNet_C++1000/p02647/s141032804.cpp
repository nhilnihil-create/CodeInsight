#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int a[N],c[N];

signed main()
{
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	while (k--)
	{
		bool flag=1;
		for (int i=0;i<=n+1;i++) c[i]=0;
		for (int i=1;i<=n;i++)
		{
			int l=max(i-a[i],1),r=min(i+a[i],n);
			c[l]++;
			c[r+1]--;
		}
		for (int i=1;i<=n;i++) a[i]=c[i]+=c[i-1];
		for (int i=1;i<=n;i++)
		if (a[i]!=n) flag=0;
		if (flag) break;
	}
	for (int i=1;i<=n;i++) print(a[i],' ');

	return 0;
}