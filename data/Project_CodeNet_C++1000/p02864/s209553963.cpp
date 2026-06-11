#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e15;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

ll dp[310][310][310];

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> H(N+1,0);
    rep(i,N) cin >> H[i+1];
    rep(i,N+1) rep(j,K+1) rep(k,N+1) dp[i][j][k]=IINF;
    dp[0][0][0]=0;
    rep2(i,1,N+1){
        rep(j,K+1){
            rep(k,N+1){
                chmin(dp[i][j][i],dp[i-1][j][k]+max(0LL,H[i]-H[k]));
                if (j<K) chmin(dp[i][j+1][k],dp[i-1][j][k]);
            }
        }
    }
    ll ans=IINF;
    rep(i,K+1) rep(j,N+1) chmin(ans,dp[N][i][j]);
    cout << ans << endl;
}