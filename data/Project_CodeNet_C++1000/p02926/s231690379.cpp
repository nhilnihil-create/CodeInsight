#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
using namespace std;
inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
struct node{
	int x,y;
}a[105];
inline bool cmp(node p,node q){return atan2(p.y,p.x)<atan2(q.y,q.x);}
int main()
{
	ri n=read();
	rep(i,0,n-1) a[i].x=read(),a[i].y=read();
	sort(a,a+n,cmp);
	ll ans=0;
	rep(i,0,n-1){
		ri x=0,y=0;
		rep(j,0,n-1){
			x+=a[(i+j)%n].x;
			y+=a[(i+j)%n].y;
			ans=max(ans,1ll*x*x+1ll*y*y);
		}
	}
	printf("%.12lf",sqrt(ans));
	return 0; 
}