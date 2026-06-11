#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define ins insert
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

ll ans,n;
set <ll> s;
set <ll>::iterator it;

inline bool jud(ll x)
{
	ll p=n;
	while(p%x==0)
	{
		ll p2=p/x;
		if(p2%x==1) return true;
		p=p/x;
	}
	return false;
}

int main()
{
	cin>>n; ans=1; s.ins(n);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(jud(i)) s.ins(i);
			if(i*i!=n&&jud(n/i)) s.ins(n/i);
		}
	}
	for(ll i=1;i*i<=(n-1);i++)
	{
		if((n-1)%i==0)
		{
			if(n%i!=0) s.ins(i);
			if(i*i!=(n-1)&&n%((n-1)/i)!=0) s.ins((n-1)/i);
		}
	}
	it=s.end(); it--;
	cout<<s.size()<<endl;
	return 0;
}