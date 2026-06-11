#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    if(K>(N-1)*(N-2)/2){cout<<-1<<endl;return 0;}
    ll t=(N-1)*(N-2)/2-K;
    deque<P> ans;
    for(ll i=2;i<=N;i++){
        ans.emplace_back(P(1,i));
    ;}
    deque<P> deq;
    for(ll i=2;i<=N-1;i++){
     for(ll j=i+1;j<=N;j++){
         deq.emplace_back(P(i,j));
     ;}
    ;}
    for(ll i=0;i<t;i++){
        ans.emplace_back(deq[i]);
    ;}
    cout<<N-1+t<<endl;
    while(!ans.empty()){
        cout<<ans.front().first<<" "<<ans.front().second<<endl;
        ans.pop_front();
    }
    
    
    return 0;
}
