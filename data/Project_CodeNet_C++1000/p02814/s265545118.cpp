#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;


#define _GLIBCXX_DEBUG
#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define MUL(a,b) a=(a*b)%mod

ll TwoCount(ll x){
    ll ret=0;
    rep(i,100000){
        if(x%2) return i;
        x/=2;
    }
    return 100000;
}

ll Gcd(ll a, ll b){
    if(a<b) return Gcd(b,a);
    return a%b ? Gcd(b,a%b) : b;
}

ll Solve(){
    ll N,M; cin>>N>>M;
    vec d(N);
    rep(i,N) cin>>d[i];
    ll Count=TwoCount(d[0]);
    REP(i,1,N) if(TwoCount(d[i])!=Count) return 0;
    rep(i,N) d[i]/=2;
    ll LCM=1;
    rep(i,N){
        LCM*=(d[i]/Gcd(LCM,d[i]));
        if(LCM>M) return 0;
    }
    M/=LCM;
    return (M+1)/2;

}


int main(){
    cout<<Solve()<<endl;
}