#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,a[10010];
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<m;i++)
		a[i]=1;
		int sum=n-m;
		a[m-1]+=sum;
		printf("%d\n",a[m-1]-a[0]);
	}
	return 0;
}