#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-9
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
double dist(ll x,ll y){
	return sqrt(x*x+y*y);
}
ll naiseki(ll x1,ll y1,ll x2,ll y2){
	return x1*x2+y1*y2;
}
int main(){
	int N;
	ll x[101],y[101];
	vector<pair<double,pll> > arg;
	scan(N);
	rep(i,N){
		scan(x[i]>>y[i]);
		arg.push_back({atan2(y[i],x[i]),{x[i],y[i]}});
	}
	double ans=0;
	sort(ALL(arg));
	rep(i,N){
		ll oldx=0,oldy=0;
		rep(j,N){
			ll newx=arg[(i+j)%N].second.first,newy=arg[(i+j)%N].second.second;
			ll nowx=oldx+newx,nowy=oldy+newy;
			oldx=nowx,oldy=nowy;
			ans=max(ans,dist(nowx,nowy));
		}
	}
	prin(setprecision(12)<<ans);
	return 0;
}
