#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 55
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
typedef pair<int,int> pii;
int n,ans;
struct data{int x,y;
}a[N];
map<pii,int> f;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			ans=max(ans,++f[make_pair(a[i].x-a[j].x,a[i].y-a[j].y)]);
		}
	cout<<n-ans;
	return 0;
	//NOTICE LONG LONG!!!!!
}