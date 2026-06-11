#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define Mid ((l+r)/2)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int maxn=3e5+5,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,Q,K,T,H,W;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}int X[maxn],Y[maxn];
int maxx,maxy,sumx,sumy;
bool px[maxn],py[maxn];
int h[maxn],w[maxn];
signed main(){
    //file(a);
	H=read(),W=read(),m=read();
	rep(i,1,m){
		h[i]=read(),w[i]=read();
		X[h[i]]++,Y[w[i]]++;
	}
	rep(i,1,H)maxx=max(maxx,X[i]);
	rep(i,1,W)maxy=max(maxy,Y[i]);
	rep(i,1,H)if(X[i]==maxx)sumx++,px[i]=true;
	rep(i,1,W)if(Y[i]==maxy)sumy++,py[i]=true;
	int cnt=0;
	rep(i,1,m)if(px[h[i]]&&py[w[i]])++cnt;
	if(cnt>=sumx*sumy)printf("%lld\n",maxx+maxy-1);
	else printf("%lld\n",maxx+maxy);


    return 0;
}
