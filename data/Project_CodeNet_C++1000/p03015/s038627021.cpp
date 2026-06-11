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

signed main(){
    string L;cin>>L;
    int N=L.size();
    int dpk[N+1];
    int dpm[N+1];
    REPS(i,N){
        int d=L[i-1]-'0';
        if(i==1){
            dpk[1]=1;
            dpm[1]=2;
        }
        else{
            dpk[i]=dpk[i-1]*3%MOD;
            dpm[i]=dpm[i-1];
            if(d==1){
                dpk[i]+=dpm[i-1];
                dpm[i]+=dpm[i-1];
                dpk[i]%=MOD;
                dpm[i]%=MOD;
            }
        }
    }
    cout<<(dpk[N]+dpm[N])%MOD<<endl;
}