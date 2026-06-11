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

void Add(ll &a, ll b){
    a=(a+b)%mod;
    return;
}

void Pro(ll &a, ll b){
    a=(a*b)%mod;
    return;
}

struct Kai{
    ll left; ll right; ll sa; ll cost;
    Kai(ll l, ll r, ll s, ll c) : left(l), right(r), sa(s), cost(c) {}
};

vector<Kai> D;

vec hen(vec x){
    vec ret;
    ll Count=0;
    rep(i,x.size()){
        if(!x[i]) Count++;
        else ret.pb(Count);
    }
    return ret;
}

int main(){
    ll N,M,Q; cin>>N>>M>>Q;
    rep(i,Q){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        a--; b--;
        Kai kari(a,b,c,d);
        D.pb(kari);
    }
    vec x={};
    rep(i,M-1) x.pb(0);
    rep(i,N) x.pb(1);
    
    ll ans=-INF;
    do{
        vec f=hen(x);
        //for(auto e: x) cout<<e<<' ';
        //cout<<endl;
        //for(auto e: f) cout<<e<<' ';
        ll Count=0;
        for(auto e : D) {
            if(f[e.right]-f[e.left]==e.sa) Count+=e.cost;
        }
        //cout<<':'<<Count<<endl;
        ans=max(Count,ans);
    }while(next_permutation(ALL(x)));
    cout<<ans<<endl;

}
