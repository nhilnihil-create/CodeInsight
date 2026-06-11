#include<bits/stdc++.h>
#define ll unsigned long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],pri[N],jud[N],cnt,fac[N],num[N];
void init()
{
	jud[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!jud[i])pri[++cnt]=i,fac[i]=i;
		for(int j=1;j<=cnt&&pri[j]*i<N;j++)
		{
			jud[pri[j]*i]=1,fac[pri[j]*i]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}
int main()
{
	init(),scanf("%d",&n);
	int g,f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)g=a[i];else g=__gcd(g,a[i]);
		while(a[i]!=1)
		{
			int t=fac[a[i]];
			if(num[t])f=0;
			num[t]=1;
			while(a[i]%t==0)a[i]/=t;
		}
	}
	if(f)puts("pairwise coprime");
	else if(g==1)puts("setwise coprime");
	else puts("not coprime");
	return 0;
}
