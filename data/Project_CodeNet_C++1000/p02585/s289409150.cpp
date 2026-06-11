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

ll N,K;
vec p,c;

void input(){
    cin>>N>>K;
    c.resize(N);
    rep(i,N){
        ll x; cin>>x; x--;
        p.pb(x);
    }
    rep(i,N) cin>>c[i];
}

ll memo_k[5001], memo_score[5001];
ll ANS=-INF;

ll dfs(ll x, ll k, ll score){
    if(k!=K) ANS=max(ANS,score);
    if(!k) return score;
    if(memo_k[x]<0){
        memo_k[x]=k; memo_score[x]=score;
        return dfs(p[x],k-1,score+c[p[x]]);
    }
    if(2*(memo_k[x]-k)<=k){
        ll kk=memo_k[x]-k, ss=-memo_score[x]+score;
        return dfs(x,kk+(k%kk),score+ss*((k/kk)-1));
    }
    return dfs(p[x],k-1,score+c[p[x]]);
}

void init(){
    rep(i,N) memo_k[i]=-1;
    rep(i,N) memo_score[i]=0;
    return;
}

int main(){
    input();
    vec ans(N,0);
    rep(i,N){
        init();
        ans[i]=dfs(i,K,0);
    }

    cout<<ANS<<endl;


}