#include<cstdio>
#include<algorithm>
#define maxn 2000005
using namespace std;
int a[maxn];
int main(void)
{
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		a[t]++;
	}
	int sum=0;
	for(int i=0;i<maxn;++i)
	{
		if(a[i]==1)
		sum++;
		if(a[i]>0)
		{
			for(int j=i;j<maxn;j+=i)
			{
				a[j]=0;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}