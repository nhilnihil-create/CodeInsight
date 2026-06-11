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
    ll K;
    cin >> K;
    vector<ll> A(N+1,0);
    for(ll i=0;i<N;i++){
        cin>>A[i+1]
    ;}
    ll sum=1;
    Map m;
    for(ll i=0;i<=N;i++){
        sum+=A[i]-1;
        sum%=K;
        m[sum].emplace_back(i);
    ;}
    ll ans=0;
    for(auto p: m){
        for(ll i=0;i<p.second.size();i++){
            ans+=lower_bound(p.second.begin(), p.second.end(), p.second[i]+K)-1-i-p.second.begin()
        ;}
    ;}
    cout<<ans<<endl;
    return 0;
}
