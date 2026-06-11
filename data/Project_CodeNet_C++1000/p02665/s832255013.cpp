#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
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
int a[100010];
long long b[100010];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n=read();long long ans=0;
	for(int i=0;i<=n;i++)a[i]=read(),ans+=a[i];
	for(int i=n;i>=0;i--)b[i]=b[i+1]+a[i];
	long long now=1-a[0];bool pd=true;
	ans+=now;if(now<0)pd=false;
	for(int i=1;i<=n;i++)
	{
		now=min(2*now-a[i],b[i+1]);
		if(now<0){pd=false;break;}
		ans+=now;
	}
	if(pd==true)printf("%lld\n",ans);
	else puts("-1");
	return 0;
}