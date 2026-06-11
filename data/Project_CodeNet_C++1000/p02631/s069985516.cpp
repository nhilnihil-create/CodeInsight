#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int main(void)
{
	unsigned int s,a[200000],x,b[200000];
	int n,i;
	scanf("%d",&n);
	s=0;
	for(i=0;i<n;i++)	{
		scanf("%u",&a[i]);
		s^=a[i];
	}
	for(i=0;i<n;i++)	{
		b[i]=s^a[i];
	}
	printf("%u",b[0]);
	for(i=1;i<n;i++)	printf(" %u",b[i]);
	printf("\n");
	return 0;
}