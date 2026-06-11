#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 100010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,a[N];
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int p=0;
	for (int i=1;i<=n;i++) if (a[i]<0) p=i;
	p=max(p,1);p=min(p,n-1);
	//让前p个被减掉
	int s=0;
	for (int i=1;i<=p;i++)  s-=a[i];
	for (int i=p+1;i<=n;i++) s+=a[i];
	cout<<s<<endl;
	for (int i=p+1;i<n;i++)
	{
		printf("%d %d\n",a[p],a[i]);
		a[p]-=a[i];
	}
	printf("%d %d\n",a[n],a[p]);a[n]-=a[p];
	for (int i=1;i<p;i++)
	{
		printf("%d %d\n",a[n],a[i]);
		a[n]-=a[i];
	}
	return 0;
	//NOTICE LONG LONG!!!!!
}