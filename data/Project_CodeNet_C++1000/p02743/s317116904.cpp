#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<bitset>
#define int long long
using namespace std;
const int Maxn=100005,L=100005;
const double PI = acos(-1.0);
__int128 a,b,c,ans1,ans2;
/*
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int a)
{
	if(a<0)
	{
		putchar('-');
		write(-a);
	}
	else
	{
		if(a>=10)
			write(a/10);
		putchar(a%10+'0');
	}
}
*/
inline __int128 read()
{
	__int128 x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

inline void write(__int128 x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	a=read(),b=read(),c=read();
	ans1=c-a-b;
	if(ans1>0)
	{
		ans1=ans1*ans1;
		ans2=4*a*b;
//	cout<<ans1<<' '<<ans2;
		if(ans2<ans1)
			puts("Yes");
		else
			puts("No");
	}
	else
	{
			puts("No");
	}
	return 0;
}

