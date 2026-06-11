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

vec unable={-1};
vec Solve(){
    ll N,M; cin>>N>>M;
    string S; cin>>S;
    vec d;
    rep(i,N+1) if(S[i]=='0') d.pb(i);
    ll A=d.size();
    rep(i,A-1) if(d[i+1]>d[i]+M) return unable;
    vec L(A,0), R(A,0);
    REP(i,1,A){
        ll x=lower_bound(ALL(d),d[i]-M)-d.begin();
        L[i]=L[x]+1;
    }
    //cout<<"Steps is "<<L[A-1]<<endl;
    vec ret;
    for(int i=A-2; i>=0; i--){
        ll x=upper_bound(ALL(d),d[i]+M)-d.begin();
        x--;
        R[i]=R[x]+1;
        //if(R[i]<=ret.size() && L[i]+R[i]==L[A-1]) ret.pb(d[i]);
    }
    ll count=0, l=0;
    rep(i,A){
        if(L[i]+R[i]==R[0]) if(L[i]>l){
            ret.pb(d[i]-count);
            count=d[i];
            l++;
        }
    }
    return ret;

}

int main(){
    vec ans=Solve();
    rep(i,ans.size()) cout<<ans[i]<<endl;
}