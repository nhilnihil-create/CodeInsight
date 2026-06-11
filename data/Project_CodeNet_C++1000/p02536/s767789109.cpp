#include <bits/stdc++.h>
#include <stdlib.h>
#include <atcoder/all>
using namespace atcoder;
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
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())

void Add(ll &a, ll b){a=(a+b)%mod;}
void Pro(ll &a, ll b){a=(a*b)%mod;}

int main(){
    ll N,M; cin>>N>>M;
    dsu d(N);
    rep(i,M){
        ll x,y; cin>>x>>y; x--; y--;
        d.merge(x,y);
    }
    cout<<d.groups().size()-1<<endl;
}