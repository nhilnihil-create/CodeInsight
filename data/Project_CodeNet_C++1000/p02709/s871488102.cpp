#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double PI=3.1415926535897932;
const double LIT=0.000000001;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define PRO(a,b) a=(a*b)%mod

ll N; vec d;
priority_queue<P> Q;

void input(){
    cin>>N;
    rep(i,N){
        ll x; cin>>x;
        d.pb(x);
    }
    rep(i,N) Q.push(mp(d[i],i));
}


ll dp[2001][2001];

ll Solve(){
    rep(i,N){
        ll x=Q.top().first, z=Q.top().second;
        Q.pop();
        rep(j,i+1) {
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(N-1-j-z)*x);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(z-(i-j))*x);
        }
    }
    ll ans=0;
    rep(i,N+1) ans=max(dp[N][i],ans);
    return ans;
}

int main(){
    input();
    cout<<Solve()<<endl;
}