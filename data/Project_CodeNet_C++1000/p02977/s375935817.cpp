//%std
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
void report(int x,int y)
{
	printf("%d %d\n",x,y);
}
int N;
void solve(int n)
{
	report(1,2);
	report(2,3);
	report(3,1+N);
	report(1+N,2+N);
	report(2+N,3+N);
	for(int i=4;i<=n;i+=2)
	{
		report(1+N,i+N);
		report(i+N,i+1+N);
		report(1+N,i+1);
		report(i+1,i);
	}
}
int main()
{
	int n=read();
	N=n;
	if(__builtin_popcount(n)==1)
		puts("No");
	else
	{
		puts("Yes");
		if(n&1)
			solve(n);
		else
		{
			solve(n-1);
			for(int i=2;i<n;++i)
			{
				int j=(n+1)^i;
				if(1<j && j<n && i!=j)
				{
					report(n,i&1?i:i+N);
					report(n+N,j&1?j:j+N);
					break;
				}
			}
		}
	}
	return 0;
}
