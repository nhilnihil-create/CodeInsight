#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=100010;
const int inf=2147483647;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
LL b[70],S=0,a[Maxn];int n;
void insert(LL x)
{
	for(int i=60;i>=0;i--)
	if(!(S&(1LL<<i))&&(x&(1LL<<i)))
	{
		if(!b[i]){b[i]=x;return;}
		x^=b[i];
	}
	for(int i=60;i>=0;i--)
	if((S&(1LL<<i))&&(x&(1LL<<i)))
	{
		if(!b[i]){b[i]=x;return;}
		x^=b[i];
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)S^=(a[i]=read());
	for(int i=1;i<=n;i++)insert(a[i]);
	LL ans=0;
	for(int i=60;i>=0;i--)
	if(!(S&(1LL<<i))&&!(ans&(1LL<<i)))ans^=b[i];
	for(int i=60;i>=0;i--)
	if((S&(1LL<<i))&&(ans&(1LL<<i)))ans^=b[i];
	printf("%lld",ans+(S^ans));
}