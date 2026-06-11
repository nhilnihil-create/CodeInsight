#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n<=2) return puts("No"),0;
	for(int i=0;i<20;++i) if(n==(1<<i)) return puts("No"),0;
	puts("Yes");
	printf("%d %d\n",2,1);
	printf("%d %d\n",1,3);
	printf("%d %d\n",3,n+2);
	printf("%d %d\n",n+2,n+1);
	printf("%d %d\n",n+1,n+3);
	for(int i=4;i<n;i+=2)
	{
		printf("%d %d\n",1,i+1);
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",1,i+n);
		printf("%d %d\n",i+n,i+n+1);
	}
	if(!(n&1))
	{
		int cur=n^1;
		int up=1<<((int)log2(cur));
		printf("%d %d\n",n,up+n);
		printf("%d %d\n",n+n,cur^up&1?cur^up:(cur&up)+n);
	}
}
