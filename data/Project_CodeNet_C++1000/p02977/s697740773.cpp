#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	m=1;
	while(m-1<=n)m<<=1;
	m>>=1;
	m--;
	if(n==m+1||n==1)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<m;i++)
	  printf("%d %d\n%d %d\n",i,i+1,n+i,n+i+1);
	printf("%d %d\n",m,n+1);
	if(n==m)return 0;
	printf("1 %d\n%d %d\n1 %d\n%d %d\n",m+1,m+1,m+2,n+m+2,n+m+2,n+m+1);
	for(int i=m+3;i<=n;i++)
	  printf("%d %d\n%d %d\n",i+n-1,i,i-m-1,i+n);
	return 0;
}