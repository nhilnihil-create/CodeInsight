#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
#define db double
#define pdd pair<db,db>
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}

const int N=105;
int n;
vector<pdd> v;
#define fi first
#define se second
int main()
{
	n=read();
	rep(i,1,n) v.pb(mp(1.0*read(),1.0*read()));
	db mx=0;
	rep(i,0,359){
		db tarx=cos(i),tary=sin(i),tx=0,ty=0;
		rep(j,0,n-1)
			if((tarx*v[j].fi+tary*v[j].se)>0){
				tx+=v[j].fi;ty+=v[j].se;
			}
		db tans=sqrt(tx*tx+ty*ty);
		if(tans>mx) mx=tans;
	}
	printf("%.12lf",mx);
	return 0; 
}