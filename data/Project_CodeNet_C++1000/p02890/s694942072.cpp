#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
int cnt[300010];
int main()
{
    //freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)cnt[read()]++;
	sort(cnt+1,cnt+n+1);
	int now=n,sum=n,p=1;
	for(int i=n;i>=0;i--)
	{
		while(now>cnt[i])
		{
			int uf=sum+(n-i)*now;
			while(p<=uf/now && p<=n)pr2(now),p++;
			now--;
		}sum-=cnt[i];
	}while(p<=n)pr2(0),p++;
	return 0;
}