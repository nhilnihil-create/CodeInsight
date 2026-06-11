#include <cstdio>
using namespace std;
#define MAX_N 123500
int prime[MAX_N*2];
void eratos()
{
	for(int i=0;i<MAX_N*2;i++)prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i*i<=MAX_N*2;i++)if(prime[i])
	{
		for(int j=i*2;j<=MAX_N*2;j+=i)prime[j]=0;
	}
	return;
}
int main()
{
	eratos();
	for(int i=1;i<MAX_N*2;i++)prime[i]+=prime[i-1];
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",prime[2*n]-prime[n]);
	}
	return 0;
}