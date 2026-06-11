#include<bits/stdc++.h>
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
int a[N];
int x[N],y[N],cnt=0;

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int now=n-1;
	while (now>1&&a[now]>=0)
	{
		cnt++;
		x[cnt]=a[1];
		y[cnt]=a[now];
		a[1]-=a[now];
		now--;
	}
	for (int i=1;i<=now;i++)
	{
		cnt++;
		x[cnt]=a[n];
		y[cnt]=a[i];
		a[n]-=a[i];
	}
	print(a[n]);
	for (int i=1;i<=cnt;i++)
	{
		print(x[i],' ');
		print(y[i]);
	}

	return 0;
}