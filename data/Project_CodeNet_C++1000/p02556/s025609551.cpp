#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=200010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n; 
LL u11,u10,u01,u00;
void upd(LL&x,LL y){x=max(x,y);}
int main()
{
	n=read();
	u11=u10=u01=u00=-inf;
	for(int i=1;i<=n;i++)
	{
		LL x=read(),y=read();
		upd(u11,x+y);
		upd(u10,x-y);
		upd(u01,-x+y);
		upd(u00,-x-y);
	}
	LL ans=0;
	upd(ans,u11+u00);
	upd(ans,u10+u01);
	printf("%lld",ans);
}