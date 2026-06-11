#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],ans,pre[maxn],k;
map <ll,int> p;

int main()
{
	n=read(); k=read(); rep(i,1,n) a[i]=read(); p[0]++;
	rep(i,1,n) a[i]=(a[i]-1)%k,pre[i]=(pre[i-1]+a[i])%k;
	rep(i,1,n)
	{
		if(i>=k) p[pre[i-k]]--;
		ans+=p[pre[i]]; p[pre[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}