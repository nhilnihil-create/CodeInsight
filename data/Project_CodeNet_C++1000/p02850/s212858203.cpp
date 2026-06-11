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
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd>> Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

vector<P> d[100010];
ll Oya[100010];
void dfs(ll x){
    rep(i,d[x].size()){
        ll A=d[x][i].first;
        if(A!=Oya[x]){
            Oya[A]=x;
            dfs(A);
        }
    }
    return;
}

int main(){
    rep(i,100010) Oya[i]=-1;
    ll N; cin>>N;
    rep(i,N-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        d[a].pb(mp(b,i));
        d[b].pb(mp(a,i));
    }
    ll K=0, Top=-1;
    rep(i,N) {
        if(d[i].size()>K){
            Top=i;
            K=d[i].size();
        }
    }
    //cout<<K<<' '<<Top<<endl;
    vec ans(N-1);
    vec memo(N,K);
    queue<ll> Q;
    Q.push(Top);
    dfs(Top);
    while(!Q.empty()){
        ll a=Q.front();
        Q.pop();
        rep(i,d[a].size()){
            ll X=d[a][i].first, Y=d[a][i].second;
            if(X!=Oya[a]){
                ans[Y]=memo[a]%K;
                memo[a]++;
                memo[X]=memo[a];
                Q.push(X);
            }
        }
    }
    cout<<K<<endl;
    rep(i,N-1) cout<<ans[i]+1<<endl;


}