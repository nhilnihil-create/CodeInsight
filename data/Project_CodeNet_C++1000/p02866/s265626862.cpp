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
const int MOD=998244353;
const int MAX=200001;
int fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

int COM(int n,int k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int powMOD(int n,int r){
    if(r==0)return 1;
    if(r%2==0)return powMOD(n,r/2)*powMOD(n,r/2)%MOD;
    if(r%2==1)return powMOD(n,r-1)*n%MOD;
}

signed main(){
    int n;cin>>n;
    int d[n];
    REP(i,n)d[i]=0;
    int MA=0;
    REP(i,n){
        int a;cin>>a;
        chmax(MA,a);
        if(i==0&&a!=0){
            cout<<0<<endl;
            return 0;
        }
        if(i!=0&&a==0){
            cout<<0<<endl;
            return 0;
        }
        d[a]++;
    }
    int ans=1;
    REPS(i,MA){
        ans*=powMOD(d[i-1],d[i]);
        ans%=MOD;
    }
    cout<<ans<<endl;
}
