#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n==(n&-n))return printf("No"),0;
	printf("Yes\n");
	printf("%d %d\n",n+1,n+2);
	for(int i=2;i+1<=n;i+=2)
	{
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+n,i+n+1);
		printf("%d %d\n",1,i);
		printf("%d %d\n",1,i+n+1);
	}
	if(n%2==0)
	{
		printf("%d %d\n",n,2*n-1);
		printf("%d %d\n",2*n,(n^(n-1)^1));
	}
	return 0;
}
