#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string L;cin>>L;
    ll dp[100005][2];//i桁目まで見ている　smaller?  のときの

    rep(i,100005) dp[i][true]=dp[i][false]=0;
    dp[0][false]=1;

    rep(i,L.size()){
        //小さいことは確定しているから、(0,0),(1,0),(0,1)のいずれでもいい
        dp[i+1][true]+=3*dp[i][true];
        dp[i+1][true]%=mod;
        
        if(L[i]=='1'){
            //一致((0,1),(1,0))
            dp[i+1][false]+=2*dp[i][false];
            dp[i+1][false]%=mod;
            //不一致((0,0))
            dp[i+1][true]+=dp[i][false];
            dp[i+1][true]%=mod;
        }else{
            //(0,0)のみ
            dp[i+1][false]+=dp[i][false];
            dp[i+1][false]%=mod;
        }
    }

    cout<<(dp[L.size()][true]+dp[L.size()][false])%mod<<endl;

    return 0;
}