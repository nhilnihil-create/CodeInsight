#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;
const ll mod=1e9+7;

int n,m;
vector<ll> a(100100);
vector<ll> dp(100100);

int main(){
    cin>>n>>m;
    rep(i,m){
        cin>>a[i];
        dp[a[i]]=1;
    }
    dp[0]=1;
    if(a[0]!=1) dp[1]=1;
    else dp[1]=0;

    for(int i=2;i<=n;i++){
        if(dp[i]==1){
            dp[i]=0;
        }
        else{
            dp[i]=dp[i-2]+dp[i-1];
            dp[i]%=mod;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}