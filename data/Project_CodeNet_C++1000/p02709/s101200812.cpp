//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define dcml(n) fixed<<setprecision(n)
using namespace std;
struct Baby{
    ll idx0,actv;
    bool operator>(const Baby& r) const{
        return actv>r.actv;
    }
};
int main(void){
    ll N;cin>>N;
    vector<Baby> v;
    REP(i,N){
        ll a;cin>>a;
        v.push_back({i,a});
    }
    sort(ALLv(v),greater<Baby>());
    /*cout<<v[0].idx<<" "<<v[0].actv<<"\n";
    cout<<v[3].idx<<" "<<v[3].actv<<"\n";*/
    
    vector<vi> dp=vector<vi>(2001,vi(2001,0));ll ans=0;
    REP(l,N){
        REP(r,N){
            if(l+r==N){
                ans=max(ans,dp[l][r]);
                break;
            }
            ll idx=l+r;
            dp[l+1][r]=max(
                dp[l+1][r],
                dp[l][r]    + v[idx].actv * abs(v[idx].idx0-l)
            );
            dp[l][r+1]=max(
                dp[l][r+1],
                dp[l][r]    + v[idx].actv * abs(v[idx].idx0-(N-1-r) )
            );
        }
    }
    cout<<ans<<"\n";
}