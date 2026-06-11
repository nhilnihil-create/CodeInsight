#include<cstdio>
#define N 1000001
inline int abs(int x){return x<0?-x:x;}
int b[3],i,n,x=0;char a[N];
int main()
{
	scanf("%d%s",&n,a);
	for(i=0,n--;i<n;i++)b[a[i]=abs(a[i]-a[i+1])%3]=1;
	for(i=0,n--;i<=n;i++)if((i&n)==i)x^=a[i];
	return 0&printf("%d\n",x&~(b[1]<<1));
}