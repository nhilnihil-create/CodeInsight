#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<55)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> c(m,vector<ll>());
    vector<ll> cost(m);
    rep(i,m){
        ll b;cin>>cost[i]>>b;
        rep(j,b){
            ll C;cin>>C;C--;
            c[i].push_back(C);
        }
    }

    vector<vector<ll>> dp(1010,vector<ll>((1<<12),INF));
    dp[0][0]=0;


    rep(i,m){//i-1番目の鍵まで選択可能
        rep(j,(1<<n)){
            ll choice=0;
            rep(k,c[i].size()){//i番目の鍵が開けることができる宝箱
                choice+=(1<<c[i][k]);
            }
            chmin(dp[i+1][j|choice],dp[i][j]+cost[i]);//i番目を選択する
            chmin(dp[i+1][j],dp[i][j]);//i番目を選択しない
        }
    }

/*    rep(i,m+1){
        rep(j,1<<n){
            if(dp[i][j]!=INF) cout<<dp[i][j]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
*/

    if(dp[m][(1<<n)-1]!=INF) cout<<dp[m][(1<<n)-1]<<endl;
    else cout<<-1<<endl;

    return 0;
}