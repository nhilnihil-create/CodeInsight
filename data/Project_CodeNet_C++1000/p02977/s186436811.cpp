#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	int n=read(),cnt=0,tmp=n;
	if(n<=2) return puts("No"),0;
	while(tmp) cnt++,tmp>>=1; cnt--;
	if((1<<cnt)==n) return puts("No"),0; puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for(int i=4;i<=(n-1);i+=2)
	{
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",n+1,i+n,n+i,n+i+1,n+1,i+1,i+1,i);
	}
	if(n%2==0)
	{
		for(int i=2;i<=n-1;i++)
		{
			int t=n^1^i;
			if(t>=2&&t<=n-1)
			{
				int p1=0,p2=0;
				if(i%2==0) p1=i+n; else p1=i;
				if(t%2==0) p2=t+n; else p2=t;
				printf("%d %d\n%d %d\n",p1,n,p2,n+n);
				break;
			}
		}
	}
	return 0;
}