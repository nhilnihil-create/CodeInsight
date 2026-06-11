#include<cstdio>
#define N 200000
using namespace std;

int n,s;
int a[N+5];
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s^=a[i];
	}
	for(i=1;i<=n;i++)
		printf("%d ",s^a[i]);
	return 0;
}