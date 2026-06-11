#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
//#define file
using namespace std;

int n,i,j,k,l,x;
int jh(int t,int x,int y) {return t==x?y:(t==y?x:t);}

int main()
{
	#ifdef file
	freopen("agc035c.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	if (pow(2,floor(log2(n)))==n) {printf("No\n");return 0;}
	
	printf("Yes\n");
	if (!(n&1))
	{
		if (!(((n-1)+1)&2))
		{
			x=n^(n-1);
			fo(i,1,n-2) printf("%d %d\n",jh(i,1,x),jh(i+1,1,x));
			printf("%d %d\n",jh(n-1,1,x),jh(n+1,1+n,x+n));
			fo(i,1,n-2) printf("%d %d\n",jh(i+n,1+n,x+n),jh(i+1+n,1+n,x+n));
			printf("%d %d\n",n,n-1),printf("%d %d\n",x+n,n+n);
		}
		else
		{
			x=n^(n-2)^1;
			fo(i,1,n-4) printf("%d %d\n",jh(i,2,x),jh(i+1,2,x));
			fo(i,1,n-4) printf("%d %d\n",jh(i+n,2+n,x+n),jh(i+1+n,2+n,x+n));
			printf("%d %d\n",jh(n-3,2,x),jh(n+1,2+n,x+n));
			printf("%d %d\n",n-2,n-1),printf("%d %d\n",n-1,1),printf("%d %d\n",1,n-2+n),printf("%d %d\n",n-2+n,n-1+n);
			printf("%d %d\n",n,n-2+n),printf("%d %d\n",x,n+n);
		}
	}
	else
	if (!((n+1)&2))
	{fo(i,1,n+n-1) printf("%d %d\n",i,i+1);}
	else
	{
		fo(i,1,n-3) printf("%d %d\n",i,i+1);
		fo(i,1,n-3) printf("%d %d\n",i+n,i+1+n);
		printf("%d %d\n",n-2,n+1);
		printf("%d %d\n",n-1,n),printf("%d %d\n",n,1),printf("%d %d\n",1,n-1+n),printf("%d %d\n",n-1+n,n+n);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}