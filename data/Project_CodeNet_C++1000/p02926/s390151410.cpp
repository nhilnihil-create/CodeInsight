#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
const double pi = acos(-1.0);

signed main(){
    int n;cin>>n;
    int x[n],y[n];
    REP(i,n)cin>>x[i]>>y[i];
    double ans=0;
    for(double w=0;w<2*pi;w+=pi/18000.0){
        double vx=cos(w),vy=sin(w);
        double nx=0,ny=0;
        REP(i,n){
            double inpro = vx*x[i]+vy*y[i];
            if(inpro>0){
                nx+=x[i];
                ny+=y[i];
            }
        }
        chmax(ans,sqrt(nx*nx+ny*ny));
    }
    cout<<fixed<<setprecision(20.20)<<ans<<endl;
}