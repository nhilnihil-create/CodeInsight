#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=998244353;



int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> a(M,0);
    vector<ll> canopen(M,0);
    for(ll i=0;i<M;i++){
        cin>>a[i];
        ll b;
        cin >> b;
        for(ll j=0;j<b;j++){
            ll c;
            cin >> c;
            canopen[i]+=1<<(c-1);
        ;}
    ;}
    vector<ll> dp(1<<N,INF);
    for(ll i=0;i<M;i++){
        if(i==0){
            dp[0]=0;
            dp[canopen[i]]=a[i];
        }
        else for(ll j=0;j<(1<<N);j++){
            dp[j|canopen[i]]=min(dp[j|canopen[i]],dp[j]+a[i])
        ;}
    ;}
    if(dp[(1<<N)-1]==INF){
        cout<<-1<<endl;return 0;
    }
    cout<<dp[(1<<N)-1]<<endl;


    return 0;
}
