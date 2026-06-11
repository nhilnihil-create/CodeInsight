#include<cstdio>
int i,n;
int main()
{
	scanf("%d",&n);
	if(n==(n&-n))return 0*puts("No");
	else printf("Yes\n%d 3\n",1+n);
	if(~n&1)printf("%d %d\n%d %d\n",n,n^(n&-n),(n&-n)+n+1,n<<1);
	for(i=2;i<n;i+=2)printf("%d %d\n%d %d\n1 %d\n1 %d\n",i,i+1,i+n,i+n+1,i,i+n+1);
	return 0;
}