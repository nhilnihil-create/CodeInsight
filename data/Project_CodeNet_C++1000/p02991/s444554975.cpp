#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N, M; cin >> N >> M; 
    vector<vector<ll>> G(N);
    for(ll i = 0; i < M; i++){
        ll v, w; cin >> v >> w;
        v--;w--;
        G[v].push_back(w);
    }
    ll S, T; cin >> S >> T; S--; T--;

    vector<vector<ll>> Dist(3, vector<ll>(N));
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < N; j++) Dist[i][j] = -1;
    }

    queue<pair<ll, ll>> Q;
    Q.push(make_pair(0, S));
    Dist[0][S] = 0;
    while(!Q.empty()){
        auto q = Q.front(); Q.pop();
        ll x = q.second;
        ll c = q.first;
        ll nc = (c+1)%3;
        //cout << x << "    " << c << endl;
        for(auto v : G[x]){
            //cout << x << "  " << c << "         " << v <<"  " << nc << endl;
            if(Dist[nc][v] == -1){
                Dist[nc][v] = Dist[c][x]+1;
                Q.push(make_pair(nc, v));
            }
        }
    }
    if(Dist[0][T] != -1) cout << Dist[0][T]/3 << endl;
    else cout << -1 << endl;


}