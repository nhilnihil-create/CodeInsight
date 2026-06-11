#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define db double
#define pdd pair<db,db>
using namespace std;
int n;db x,y,mx;
vector<pdd> v;
#define fi first
#define se second
int main(){
	cin>>n;
	rep(i,1,n) cin>>x>>y,v.pb(mp(x,y));
	rep(i,0,359){
		db tarx=cos(i),tary=sin(i),tx=0,ty=0;
		rep(j,0,n-1)
			if((tarx*v[j].fi+tary*v[j].se)>0)
				tx+=v[j].fi,ty+=v[j].se;
		db tans=sqrt(tx*tx+ty*ty);
		mx=max(mx,tans);
	}
	printf("%.12lf",mx);
}