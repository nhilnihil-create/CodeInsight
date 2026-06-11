#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int MAXN=200005;
priority_queue<pii> hp;
int a[MAXN],b[MAXN],vi[MAXN],n;
int main()
{
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read(),hp.push(mp(b[i],i));
	LL ans=0;int cnt=n;
	for(int i=1;i<=n;i++)if(a[i]==b[i])--cnt,vi[i]=1;
	int t=cnt;LL kk=0;
	while(cnt)
	{
		
		pii temp=hp.top();hp.pop();t=cnt;
		if(vi[temp.second])continue;
		int ls=temp.second-1,rs=temp.second+1;
		if(!ls)ls=n;if(rs>n)rs=1;
		int g=max(b[ls],b[rs]);
		int k=ceil(double(temp.first-g)/(b[ls]+b[rs]));
		if(temp.first-k*(b[ls]+b[rs])>a[temp.second])
		{
			b[temp.second]-=k*(b[ls]+b[rs]);ans+=k;
			hp.push(mp(b[temp.second],temp.second));
		}
		else
		{
			if((temp.first-a[temp.second])%(b[ls]+b[rs]))break;
			ans+=(temp.first-a[temp.second])/(b[ls]+b[rs]);--cnt;
			
			b[temp.second]=a[temp.second];vi[temp.second]=1;
			if(b[temp.second]>=g)
			{
				if(b[ls]!=a[ls])break;if(b[rs]!=a[rs])break;
				if(!vi[ls])--cnt,vi[ls]=1;if(!vi[rs])--cnt,vi[rs]=1;
			}
		}
	}
	if(cnt)puts("-1");
	else pr2(ans);
	return 0;
}
