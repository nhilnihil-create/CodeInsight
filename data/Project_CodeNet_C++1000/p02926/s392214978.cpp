#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;
	template<class IT>inline void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=gc();}
	}
};
using io::gi;
struct qwq{
	int a,b;
	inline bool operator<(const qwq &x)const{
		return a<x.a;
	}
};
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
const int N=205;
const double pi2=M_PI*2,pie=M_PI+0.00000001;
struct node{
	int x,y;double t;
	inline bool operator<(const node &a)const{
		return t<a.t;
	}
}x[N];
inline ll sqr(int a){return ((ll)a)*a;}
int main(){
	int n,i,r;ll mx=0ll;
	scanf("%d",&n);
	for(i=1;i<=n;++i){scanf("%d%d",&x[i].x,&x[i].y);x[i].t=atan2(x[i].y,x[i].x);}
	sort(x+1,x+n+1);
	for(i=1;i<=n;++i){x[i+n]=x[i];x[i+n].t+=pi2;}
	n<<=1;
	for(i=2;i<=n;++i){x[i].x+=x[i-1].x;x[i].y+=x[i-1].y;}
//	for(i=1;i<=n;++i)printf("%d %d %lf\n",x[i].x,x[i].y,x[i].t);
	n>>=1;
	for(i=1;i<=n;++i)for(r=i;r<i+n;++r)cmax(mx,sqr(x[r].x-x[i-1].x)+sqr(x[r].y-x[i-1].y));
	printf("%.30lf",sqrt(mx));
	return 0;
}