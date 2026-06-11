#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,S; cin>>N>>S;
    vector<int> A(N); rep(i,N)cin>>A[i];
    vector<vector<ll>> dp(N+10,vector<ll>(S+10,0));
    dp[0][0] = 1;
    rep(i,N){
        rep(s,S+1){
            dp[i+1][s] = 2*dp[i][s];
            dp[i+1][s] %= MOD;
            if(A[i]<=s) dp[i+1][s] += dp[i][s-A[i]];
            dp[i+1][s] %= MOD;
        }
    }
    cout<<dp[N][S]<<endl;
}
