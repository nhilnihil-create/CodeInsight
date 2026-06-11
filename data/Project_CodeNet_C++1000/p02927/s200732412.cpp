#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
int m,d;
int main()
{
	m=read(); d=read();
	int cnt=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=d;j++)
			if((j%10)>1&&(j/10)>1&&(j%10)*(j/10)==i)++cnt;
	writeln(cnt);
	return 0;
}