#include<cstdio>
using namespace std;
const int N=1e6;
int n,x,a[N+5],b[N+5],p[N+5],t[N+5];
bool bo,bz[N+5],bz1[N+5];
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=N;i++)
	{
		if (!bz[i]) p[++p[0]]=i,t[i]=i;
		for (int j=1;j<=p[0] && p[j]*i<=N;j++)
		{
			bz[i*p[j]]=1,t[i*p[j]]=p[j];
			if (i%p[j]==0) break; 
		}
	}
	for (int i=1;i<=n;i++)
	{
		x=a[i];
		while (x>1)
		{
			if (bz1[t[x]])
			{
				bo=1;
				break;
			}
			x/=t[x];
		}
		if (bo) break;
		x=a[i];
		while (x>1)
		{
			bz1[t[x]]=1;
			x/=t[x];
		}
	}
	if (!bo)
	{
		printf("pairwise coprime");
		return 0;
	}
	x=a[1];
	for (int i=2;i<=n;i++) x=gcd(x,a[i]);
	if (x==1) printf("setwise coprime"); else printf("not coprime");
	return 0;
} 