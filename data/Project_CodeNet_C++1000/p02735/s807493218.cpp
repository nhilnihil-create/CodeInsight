#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    vector<vector<char>> S(H, vector<char>(W));
    for(ll i=0;i<H;i++){
       for(ll j=0;j<W;j++){
           cin>>S[i][j]
       ;}
    ;}
    vector<vector<ll>> dp(H, vector<ll>(W, INF));
    if(S[0][0]=='.')dp[0][0]=0;
    else dp[0][0]=1;
    for(ll i=0;i<H;i++){
       for(ll j=0;j<W;j++){
           if(S[i][j]=='.'){
               if(i-1>=0){
                   chmin(dp[i][j],dp[i-1][j]);
               }
               if(j-1>=0){
                   chmin(dp[i][j],dp[i][j-1]);
               }
           }
           else{
               if(i-1>=0){
                   if(S[i-1][j]=='#'){
                       chmin(dp[i][j],dp[i-1][j]);
                   }
                   else chmin(dp[i][j],dp[i-1][j]+1);
               }
               if(j-1>=0){
                   if(S[i][j-1]=='#'){
                       chmin(dp[i][j],dp[i][j-1]);
                   }
                   else chmin(dp[i][j],dp[i][j-1]+1);
               }
           }
       ;}
    ;}
    print(dp[H-1][W-1]);

    return 0;
}
