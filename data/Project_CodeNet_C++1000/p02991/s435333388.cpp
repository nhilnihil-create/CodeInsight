#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P= pair<ll,ll>;
const ll INF = ll(1e18)+5;
const ll MAXN = ll(1e5) +5;
vector<vector<ll>> G(3*MAXN);
vector<ll> d(3*MAXN,INF);

int main() {
    ll N,M;
    cin >> N >>M;
    
    for(int i=0;i<M;i++){
        ll u,v;
        cin >> u >> v;
        --u;--v;
        G[u*3].push_back(v*3+1);
        G[u*3 +1].push_back(v*3+2);
        G[u*3+2].push_back(v*3);
    }
    ll S,T;
    cin >> S >>T;
    --S;--T;
    
    d[3*N]=0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(P(0,3*S));
    while(!pq.empty()){
        P p= pq.top();
        pq.pop();
        if(d[p.second] <p.first){
            continue;
        }
        for(ll child:G[p.second]){
            if(d[child] > p.first+1){
                d[child] = p.first+1;
                pq.push(P(d[child],child));
            }
        }
    }
    if(d[T*3]==INF){
        cout << -1<<endl;
        return 0;
    }
    cout << d[T*3]/3 << endl;


    return 0;
}