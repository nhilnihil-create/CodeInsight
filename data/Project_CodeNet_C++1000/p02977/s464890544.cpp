#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long LL;

const int maxn=2e5+5;

int n;

int main()
{
	scanf("%d",&n);
	if (n==1) {puts("No"); return 0;}
	
	double dt=log(n)/log(2);
	int t=dt;
	if ((1<<t)==n) {puts("No"); return 0;}
	
	puts("Yes");
	for(int i=2; i+1<=n; i+=2)
	{
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+1,1);
		printf("%d %d\n",1,n+i);
		printf("%d %d\n",n+i,n+i+1);
	}
	printf("2 %d\n",1+n);
	
	if (!(n&1))
	{
		printf("%d %d\n",n,(1<<t)+1);
		printf("%d %d\n",n-(1<<t)+n,n+n);
	}
}