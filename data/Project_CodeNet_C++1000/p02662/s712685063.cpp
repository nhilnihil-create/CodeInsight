#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=998244353;
int main(void){
    ll n,s;cin>>n>>s;
    vector<vector<ll>> dp(n+100,vector<ll>(4000,0));
    dp[0][0]=1;
    rep(i,n){
        ll a;cin>>a;
        rep(j,s+1){
            dp[i+1][j]+=dp[i][j]*2;
            dp[i+1][j]%=mod;
            if(j+a<=s) dp[i+1][j+a]+=dp[i][j];
            dp[i+1][j+a]%=mod;
        }
        //cout<<dp[i+1][s]<<endl;
    }
    ll res=dp[n][s];
    cout<<res<<endl;
}