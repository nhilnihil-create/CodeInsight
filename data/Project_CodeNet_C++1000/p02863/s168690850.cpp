#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    ll T;
    cin >> T;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]>>B[i]
    ;}
    //dp[i][j]はi番目までをみて、j分以下かかるときの最大食量
    vector<vector<ll>> dp(N, vector<ll>(T+1, 0));
    //dp2[i][j]はi番目までをみて、j分以下かかるときの最大食量
    vector<vector<ll>> dp2(N, vector<ll>(T+1, 0));
    for(ll i=0;i<N;i++){
     for(ll j=0;j<=T;j++){
         if(i==0){
            if(j>=A[0])dp[i][j]=B[0];
         }
         else{
             if(j<A[i])dp[i][j]=dp[i-1][j];
             else dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i]]+B[i]);
         }
     ;}
    ;}
    for(ll i=N-1;i>=0;i--){
     for(ll j=0;j<=T;j++){
         if(i==N-1){
            if(j>=A[N-1])dp2[i][j]=B[N-1];
         }
         else{
             if(j<A[i])dp2[i][j]=dp2[i+1][j];
             else dp2[i][j]=max(dp2[i+1][j],dp2[i+1][j-A[i]]+B[i]);
         }
     ;}
    ;}
    ll ans=0;
    for(ll i=0;i<N;i++){
     for(ll j=0;j<=T-1;j++){
         if(i!=0&&i!=N-1)
         ans=max(ans,B[i]+dp[i-1][j]+dp2[i+1][T-1-j]);
         else if(i==0){
             ans=max(ans,B[i]+dp2[i+1][T-1-j]);
         }
         else if(i==N-1){
             ans=max(ans,B[i]+dp[i-1][j]);
         }
     ;}
    ;}
    cout<<ans<<endl;
    return 0;
}
