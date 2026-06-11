#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,n,k,p[1000],sum=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)	scanf("%d",&p[i]);
	sort(p,p+n);
	for(i=0;i<k;i++)	sum+=p[i];
	printf("%d\n",sum);
	return 0;
}
