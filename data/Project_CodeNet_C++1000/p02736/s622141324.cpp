#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,a[N],b[N],fac[N];
char ch[N];
bool bl;
int C(int n,int m)
{
	return (n&m)==m;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++) a[i]=ch[i]-'0';
	for (int i=1;i<n;i++) b[i]=abs(a[i]-a[i+1]);
	bl=1;
	for (int i=1;i<n;i++)
	{
		if (b[i]==1)
		{
			bl=0;
			break;
		}
	}
	if (bl)
	{
		for (int i=1;i<n;i++)
		  b[i]/=2;
	}
	for (int i=1;i<n;i++) b[i]%=2;
	int ans=0;
	for (int i=1;i<n;i++) ans=(ans+C(n-2,i-1)*b[i])%2;
	if (bl) ans*=2;
	printf("%d\n",ans);
}