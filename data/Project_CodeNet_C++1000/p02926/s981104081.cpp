#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<pair<double,P>>vec;
int main(){
	cin >> n;
	rep(i,n){
		int x,y; cin >> x >> y;
		double deg = atan2((double)(y),(double)(x));
		vec.pb(mp(deg,mp(x,y)));
	}
	sort(vec.begin(),vec.end());
	rep(i,n){
		vec.pb(vec[i]);
	}
	double ans = 0;
	rep(i,2*n) rep(j,2*n){
		if(i > j || j-i+1 > n) continue;
		double sx = 0, sy = 0;
		for(int k=i;k<=j;k++) { sx += vec[k].sc.fi; sy += vec[k].sc.sc; }
		ans = max(ans,sqrt(sx*sx+sy*sy));
	}
	printf("%.12f\n",ans);
}