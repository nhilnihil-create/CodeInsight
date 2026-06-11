#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FUP(i,x,y) for(int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(int i=(x);i>=(y);i--)
#define MAXN 5010
#define INF 0x7fffffff
#define MOD 1000000007
#define ll long long
#define db double
using namespace std;
ll read(){
    ll w=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')flg=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
    return w*flg;
}
ll k,q,n,x,m,D[MAXN],d[MAXN],cnt,sum;
void init()
{
	n=x=m=cnt=sum=0;
	memset(d,0,sizeof(d));
}
int main(){
	k=read(),q=read();
	FUP(i,1,k)
	{
		D[i]=read();
	}
	while(q--)
	{
		init();
		n=read(),x=read(),m=read();
		n--;
		x%=m;
		FUP(i,1,k)
		{
			d[i]=D[i]%m;
			if(d[i]==0)
			{
				cnt++;
			}
			sum+=d[i];
		}
		cnt*=n/k,sum*=n/k;
		sum+=x;
		FUP(i,1,n%k)
		{
			if(d[i]==0)
			{
				cnt++;
			}
			sum+=d[i];
		}
		//printf("%lld,%lld,%lld\n",n,cnt,sum/m);
		printf("%lld\n",n-cnt-sum/m);
	}
    return 0;
}