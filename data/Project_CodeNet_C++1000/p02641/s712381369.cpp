#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int x,n,f[102],p,mi,mn,a,i;
	scanf("%d %d",&x,&n);
	for(i=0;i<=101;i++)	f[i]=0;
	for(i=0;i<n;i++)	{
		scanf("%d",&p);
		f[p]=1;
	}
	mn=1000;
	for(i=0;i<=101;i++)	{
		if(f[i]==0)	{
			a=i-x;
			if(a<0)	a=-a;
			if(mn>a)	{
				mn=a;	mi=i;
			}
		}
	}
	printf("%d\n",mi);
	
	return 0;
}