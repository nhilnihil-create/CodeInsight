#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
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

signed main(){
    int H,W,A,B;cin>>H>>W>>A>>B;
    char Z[H][W];
    REP(i,H)REP(j,W)Z[i][j]='0';
    REP(i,B)REP(j,A)Z[i][j]='1';
    REP(i,H-B)REP(j,W-A)Z[B+i][A+j]='1';
    REP(i,H){
        REP(j,W)cout<<Z[i][j];
        cout<<endl;
    }
}
