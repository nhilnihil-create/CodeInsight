#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2005,K=1000000007;
int n,m,p,ans,fac[maxn],inv[maxn];
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
int C(int A,int B)
{
	return (LL)fac[A]*inv[B]%K*inv[A-B]%K;
}
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(LL)fac[i-1]*i%K;
	inv[n]=Pow(fac[n],K-2);
	for (int i=n-1;i>=0;i--) inv[i]=(LL)inv[i+1]*(i+1)%K;
	m=n/3;
	for (int i=1;i<=m;i++)
	{
		p=n-i*3;
		ans+=C(i+p-1,p);
		if (ans>=K) ans-=K;
	}
	printf("%d\n",ans);
	return 0;
}
