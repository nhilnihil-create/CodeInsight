#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

int n;

int main()
{
	n=ty();
	if(!(n&(n-1))){puts("No");return 0;}
	puts("Yes");

	printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",3,1,1,2,2,n+3,n+3,n+1,n+1,n+2);
	for(int i=4;i+1<=n;i+=2)printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,i+1,i+1,1,1,n+i,n+i,n+i+1);
	if(!(n&1))
	{
		int temp=1;
		while(temp<<1<=n)temp<<=1;
		printf("%d %d\n%d %d\n",temp+1,n,n+n-temp,n+n);
	}
	
	return 0;
}
