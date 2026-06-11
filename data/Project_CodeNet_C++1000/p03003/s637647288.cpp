#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;




int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> S(N+1,0);
    vector<ll> T(M+1,0);
    for(ll i=1;i<=N;i++){
        cin>>S[i];
    ;}
    for(ll i=1;i<=M;i++){
        cin>>T[i]
    ;}

    //dp[i][j]はS[i]とT[j]を最後とする共通整数列の数
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    vector<vector<ll>> sum(N+1, vector<ll>(M+1, 0));
    for(ll i=1;i<=N;i++){
     for(ll j=1;j<=M;j++){
         if(S[i]!=T[j])dp[i][j]=0;
         else dp[i][j]=sum[i-1][j-1]+1;
         sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j]+MOD;
         sum[i][j]%=MOD;
     ;}
    ;}
    cout<<(sum[N][M]+1)%MOD<<endl;

    
    


    return 0;
}
