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
const double DEL=1e-3;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%MOD
#define CHECK cout<<"arrived"<<endl

ll d[100010][61];
ll N;
const ll BIG=100005;
ll MAX=0;

ll ruijou(ll n, ll k){
    if(!k) return 1;
    ll a=ruijou(n,k/2);
    a=(a*a);
    return k%2 ? (a*n) : a;
}

void Write(ll A,ll x){
    ll K=A;
    rep(i,61){
        if(!K) break;
        if(K%2) d[x][i]=1;
        K/=2;
        MAX=max(MAX,(ll)i+1);
    }
    return;
}

int main(){
    cin>>N;
    vec D(N);

    rep(i,N) cin>>D[i];
    rep(i,N) Write(D[i],i);
    ll SX=0;
    rep(i,N) SX^=D[i];
    Write(SX,BIG);
    vec k;
    ll ans=0;
    rep(i,MAX) {
        if(!d[BIG][i]) k.pb(i);
        else ans+=ruijou(2,i);
    }
    ll M=k.size();
    mat A(N+1,vec(M,1));
    vector<bool> used(N,false);
    rep(i,N) rep(j,M) A[i][j]=d[i][k[j]];

    /*rep(i,N){
        rep(j,M) cout<<A[i][j];
        cout<<endl;
    }*/

    for(int j=M-1; j>=0; j--){
        ll memo=-1;
        rep(i,N) if(!used[i]) if(A[i][j]){
            memo=i;
            used[i]=true;
            break;
        }
        //cout<<memo<<' '<<j<<endl;
        if(memo>=0 && memo<N){
            REP(i,memo+1,N+1) if(A[i][j]){
                rep(k,j+1) A[i][k]^=A[memo][k];
            }
        }
    }
    /*rep(j,M) cout<<A[N][j];
    cout<<endl;*/
    rep(j,M) if(!A[N][j]) ans+=ruijou(2,k[j]+1);
    cout<<ans<<endl;



}