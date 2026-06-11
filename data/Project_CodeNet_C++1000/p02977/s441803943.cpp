#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define riterator reverse_iterator
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-'0';}
	return x*f;
}

int n;

int main()
{
	scanf("%d",&n); int p = n&(-n);
	if(p==n) {puts("No"); return 0;}
	puts("Yes");
	for(int i=3; i<=n; i+=2)
	{
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i,i,i-1,1,i-1+n,i-1+n,i+n);
	}
	printf("%d %d\n",2,n+1);
	if(!(n&1))
	{
		int x = p>>1,y = (n^p)>>1;
		printf("%d %d\n%d %d\n",n,2*x+1,n+n,2*y+n);
	}
	return 0;
}