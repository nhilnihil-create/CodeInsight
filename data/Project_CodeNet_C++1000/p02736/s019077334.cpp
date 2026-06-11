//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 1000100
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
char ch[N]; int a[N],n;
int C(int n,int m){return n>=m?1:0;}
int lucas(int n,int m){if(!n||!m) return C(n&1,m&1); if(!C(n&1,m&1))	return 0; return lucas(n>>1,m>>1);}
int main()
{
	n=read(); scanf("%s",ch+1);
	for(int i=1;i<=n;i++)	a[i]=ch[i]-'1';
	int tot=0,wei=0;
	for(int i=1;i<=n;i++)	if(a[i]==1)	tot^=lucas(n-1,i-1),wei=1;
	if(tot)	return puts("1"),0;
	if(wei)	return puts("0"),0;
	for(int i=1;i<=n;i++)	a[i]>>=1;
	for(int i=1;i<=n;i++)	if(a[i]==1)	tot^=lucas(n-1,i-1),wei=1;
	if(tot)	return puts("2"),0;
	puts("0");
	return 0;
}