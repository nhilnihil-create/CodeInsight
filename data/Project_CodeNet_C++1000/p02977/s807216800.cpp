#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int main()
{
	int n,m=1;scanf("%d",&n);while(m<n)m<<=1;
	if(m==n){puts("No");return 0;}
	puts("Yes");
	printf("%d %d\n",1,n+2);printf("%d %d\n",n+2,3);
	printf("%d %d\n",3,n+1);printf("%d %d\n",n+1,2);
	printf("%d %d\n",2,n+3);
	for(int i=4;i<n;i+=2)
	{
		printf("%d %d\n",i,n+1);printf("%d %d\n",i,n+i+1);
		printf("%d %d\n",i+1,n+1);printf("%d %d\n",n+i,i+1);
	}
	if(!(n&1)){for(int i=2;i<n;++i)if((n^i^1)<n){printf("%d %d\n",n,i);printf("%d %d\n",n+n,n^i^1);break;}}
	return 0;
}