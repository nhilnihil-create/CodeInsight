#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};
ll Count=0;

ll N; vec A,B;
ll ans=0;
bool able=true;
bool same[200010];
ll SAME=0;
bool Changed=false;


void Hiku(ll x){
    //Count++;
    //cout<<x<<':'<<B[x]<<':'<<A[x]<<endl;
    //if(Count>100) return;
    if(!able) return;
    if(same[x]) return;
    if(B[x]<A[x]) {able=false; return;}
    if(B[x]==A[x]) {same[x]=true; SAME++; return;}
    ll a=(x+1)%N, c=(x-1+N)%N;
    ll K=B[a]+B[c];
    if(K>=B[x]) return;
    if(B[x]-K<A[x]){able=false; return;}
    ll P=(B[x]-A[x])/K;
    Changed=true;
    //cout<<x<<' '<<B[x]<<' '<<B[x]-(P*K)<<endl;
    B[x]-=P*K;
    ans+=P;
    if(B[x]==A[x]) {same[x]=true; SAME++;}
    return;
}

ll Solve(){
    while(true){
        Changed=false;
        rep(i,N){
            if(!able) return -1;
            if(SAME==N) return ans;
            Hiku(i);
            //cout<<"SOLVING"<<' '<<able<<' '<<SAME<<endl;
            //if(Count>100) return -1;
        }
        if(!Changed) return -1;
    }
}

int main(){
    cin>>N;
    rep(i,N){
        ll x; cin>>x;
        A.pb(x);
    }
    rep(i,N){
        ll x; cin>>x;
        B.pb(x);
    }
    cout<<Solve()<<endl;
}