#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
const int N=65;
int n,sum,a[N],b[1000005];
/*char buf[1ll<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1ll,1ll<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1ll;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
void add(int x)
{
	for(int i=60;i>=0;i--)
		if(!(sum&(1ll<<i)))
		if(x&(1ll<<i))
		{
			if(!a[i])
			{
				a[i]=x;
				return;
			}
			x^=a[i];
		}
	for(int i=60;i>=0;i--)
		if(sum&(1ll<<i))
		if(x&(1ll<<i))
		{
			if(!a[i])
			{
				a[i]=x;
				return;
			}
			x^=a[i];
		}	
}
signed main()
{
	n=read();
	for(int i=1ll;i<=n;i++)
	{
		b[i]=read();
		sum^=b[i];
	}
	for(int i=1ll;i<=n;i++)add(b[i]);
	int now=0;
	for(int i=60;i>=0;i--)
		if(!(sum&(1ll<<i)))
		if(!(now&(1ll<<i)))now^=a[i];
	for(int i=60;i>=0;i--)
		if(sum&(1ll<<i))
		if(!(now&(1ll<<i)))now^=a[i];
	cout<<(sum^now)+now;
	return 0;	
}
