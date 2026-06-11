#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef tuple<long double,ll,ll> T;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair

ll N; 
ll ans;
ll Xs;
ll Ys;
T point[105];
long double angle(ll dx,ll dy){
	long double radian=atan2(dy, dx);
	radian=radian*(180.0/M_PI);
	if(radian<0) radian+=360.0;
	return radian;
}
ll calc(ll n1,ll n2){
	if(n1>=n2) swap(n1,n2);
	ll X=0;
	ll Y=0;
	ll X1=0;
	ll Y1=0;
	ll ret1=0;
	ll ret2=0;
	for(ll i=n1; i<=n2; i++){
		X+=get<1>(point[i]);
		Y+=get<2>(point[i]);
	}
	ret1=X*X+Y*Y;
	X1=Xs-X+get<1>(point[n1])+get<1>(point[n2]);
	Y1=Ys-Y+get<2>(point[n1])+get<2>(point[n2]);
	if(n1==n2){
		X1-=get<1>(point[n1]);
		Y1-=get<2>(point[n1]);
	}
	ret2=X1*X1+Y1*Y1;
	return max(ret1,ret2);
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N; 
rep(i,N){
	ll x,y;
	cin>>x>>y;
	point[i]=T(angle(x,y),x,y);
}
sort(point,point+N);
rep(i,N){
	Xs+=get<1>(point[i]);
	Ys+=get<2>(point[i]);
}
rep(i,N){
	rep(j,N){
		ans=max(ans,calc(i,j));
	}
}
cout<<fixed<<setprecision(30)<<sqrt(ans)<<endl;
//36.138621999185303934609692078084
//42.953463189829058421764784725383

}
	