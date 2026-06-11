#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

ll n,ans;
struct node{ll x,y;}p[maxn];

inline bool cmp(node a,node b)
{
	return atan2(a.y , a.x) < atan2(b.y , b.x);
}

inline ll wk(int x,int y)
{
	ll tx=0,ty=0;
	for(int i=x;i<=y;i++) tx+=p[i].x,ty+=p[i].y;
	return tx*tx+ty*ty;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
	sort(p+1,p+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<p[i].x<<" "<<p[i].y<<endl;
	for(int i=1;i<=n;i++) p[i+n]=p[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=i+n-1;j++) ans=max(ans,wk(i,j));
	printf("%.10lf",sqrt(ans));
	return 0;
}