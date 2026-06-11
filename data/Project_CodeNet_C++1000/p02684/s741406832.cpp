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


#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define MUL(a,b) a=(a*b)%mod

ll N,K;
vec d;
vec m;

ll Solve(ll a,ll T){
    //cout<<a+1<<' '<<T<<endl;
    if(!T) return a;
    if(m[a]<0) {
        m[a]=T;
        return Solve(d[a],T-1);
    }
    ll F=m[a]-T;
    if(T>F) return Solve(a,T%F);
    return Solve(d[a],T-1);
}
int main(){
    cin>>N>>K;
    rep(i,N){
        ll x; cin>>x; x--;
        d.pb(x);
    }
    rep(i,N) m.pb(-1);
    cout<<Solve(0,K)+1<<endl;

}