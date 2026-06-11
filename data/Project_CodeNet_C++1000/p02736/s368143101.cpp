#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define N 1000005
#define MOD 2
#define INF 0x3f3f3f3f
#define LL long long
int n,num[N],fac[N],ans,fans;
char s[N];
int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f*x;
}
int Abs(int x)
{
	if(x>=0) return x;
	return -x;
}
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1ll*res*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return res;
}
int cnt(int x)
{
	int res=0;
	while(!(x&1))
		x>>=1,res++;
	return res;
}
int f(int a,int b)
{
	return fac[b]-fac[a]-fac[b-a];
}
int main()
{
	n=rd();
	scanf("%s",s+1);
	fac[0]=0;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]+cnt(i);
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		num[i]=Abs(s[i]-s[i+1]);
		if(num[i]==1)
		{
			flag=1;
			ans^=f(n-1-i,n-2)==0;
		}
		if(num[i]==2)
			fans^=f(n-1-i,n-2)==0;
	}
	if(flag)
	{
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n",fans*2);
	return 0;
}