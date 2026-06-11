#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re int n,N;
	scanf("%d",&n);
	for(N=1;N<=n;N<<=1);N>>=1;
	if(n==N){puts("No");return 0;}
	if(N==2)N=4;
	puts("Yes");
	for(re int i=1;i<N-1;i++)printf("%d %d\n%d %d\n",i,i+1,i+n,i+n+1);
	printf("%d %d\n",N-1,n+1);
	for(re int i=N;i+1<=n;i+=2)
	{
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,i+1,i+1,1,1,i+n,i+n,i+n+1);
	}
	if(!(n&1))
	{
		if((n&-n)==2)
		printf("%d %d\n",n^(n&-n)^1,n),
		printf("%d %d\n",n&-n,2*n);
		else
		printf("%d %d\n",(n^(n&-n))+n,n),
		printf("%d %d\n",n&-n,2*n);
	}
}