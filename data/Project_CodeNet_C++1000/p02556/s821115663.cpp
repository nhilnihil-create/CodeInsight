#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,d1[N],d2[N];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		d1[i]=x+y;
		d2[i]=x-y;
	}
	sort(d1+1,d1+1+n);
	sort(d2+1,d2+1+n);
	printf("%d\n",max(d1[n]-d1[1],d2[n]-d2[1]));
	return 0;
}
