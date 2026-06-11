#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=3005,K=998244353,inv2=499122177;
int n,m,a[maxn],f[maxn][maxn];
int Pow(int A,int B)
{
	int res=1;
	while (B)
	{
		if (B&1) res=(LL)res*A%K;
		A=(LL)A*A%K;
		B>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0]=Pow(2,n);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if (a[i]<=j) f[i][j]=(f[i][j]+(LL)f[i-1][j-a[i]]*inv2)%K;
		}
	printf("%d\n",f[n][m]);
	return 0;
}
