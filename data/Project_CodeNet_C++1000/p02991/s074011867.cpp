#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> u(M,0);
    vector<ll> v(M,0);
    for(ll i=0;i<M;i++){
        cin>>u[i]>>v[i];
        u[i]--;v[i]--;
    ;}
    vector<vector<ll>> hen(3*N, vector<ll>(0));
    for(ll i=0;i<M;i++){
        hen[u[i]].emplace_back(v[i]+N);
        //hen[v[i]].emplace_back(u[i]+N);
        hen[u[i]+N].emplace_back(v[i]+2*N);
        //hen[v[i]+N].emplace_back(u[i]+2*N);
        hen[u[i]+2*N].emplace_back(v[i]);
        //hen[v[i]+2*N].emplace_back(u[i]);
    ;}  
    
    ll S;
    cin >> S;
    ll T;
    cin >> T;
    S--;T--;

    //Sからの各点までの最短距離
    vector<ll> d(3*N,INF);
    d[S]=0;

    //ダイクストラ
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0,S));
    while(!pq.empty()){
        P x=pq.top();
        pq.pop();
        ll y=x.first;
        ll z=x.second;
        if(y>d[z]){continue;}
        for(ll i=0;i<hen[z].size();i++){
            ll w=hen[z][i];
            if(d[w]>d[z]+1){
                d[w]=d[z]+1;
                pq.push(P(d[w],w));
            }
        ;}
    }

    if(d[T]==INF){cout<<-1<<endl;return 0;}
    cout<<d[T]/3<<endl;
    

    return 0;
}
