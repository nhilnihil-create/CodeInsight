#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if ((n&-n)==n) return puts("No"),0;
	printf("Yes\n1 3\n3 2\n2 %d\n%d %d\n%d %d\n",n+1,n+1,n+3,n+3,n+2);
	for (int i=4; i<n; i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n",n+1,i,i,i+1,n+1,n+i+1,n+i+1,n+i);
	if (!(n&1)) 
	{
		int m;
		for (int i=16; i>=0; i--) if (n>>i&1) {m=(1<<i); break;}
		printf("%d %d\n%d %d\n",n,m,n+n,(n^m^1)+n);
	}
	return 0;
}