#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
 int main(void)
{
	int n,m,i,a;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)	{
		scanf("%d",&a);
		n=n-a;
	}
	if(n<0)	printf("-1\n");
	else printf("%d\n",n);
	return 0;
}