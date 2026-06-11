#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;
 
inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
 
ll n,a[maxn],b[maxn],ans,a1,a2;
 
inline int w(int x){if(x==0) return n; if(x==n+1) return 1; return x;}
 
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	int f=0;
	while(1)
	{
		f=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>b[w(i+1)]+b[w(i-1)])
			{
				a1+=(b[i]/(b[w(i+1)]+b[w(i-1)]));
				b[i]%=(b[w(i+1)]+b[w(i-1)]); f=1;
				if(b[i]==0) b[i]+=b[w(i+1)]+b[w(i-1)],a1--;
			}
		}
		//for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
		if(f==0) break;
	}
	//cout<<endl<<endl;
	
	while(1)
	{
		f=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[w(i+1)]+a[w(i-1)])
			{
				a2+=(a[i]/(a[w(i+1)]+a[w(i-1)]));
				a[i]%=(a[w(i+1)]+a[w(i-1)]); f=1;
				if(a[i]==0) a[i]+=a[w(i+1)]+a[w(i-1)],a2--;
			}
		}
		//for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
		if(f==0) break;
	}
	
	for(int i=1;i<=n;i++) if(a[i]!=b[i]) {puts("-1"); return 0;}
	if(a1<a2) puts("-1"); else cout<<a1-a2<<endl;
	
	return 0;
}