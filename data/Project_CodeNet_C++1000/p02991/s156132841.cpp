#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(){
    ll N, M; cin >> N >> M;
    ll u, v;
    vector<vector<ll>> G(3*N);
    for (ll i = 0; i < M; i++) {
        cin >> u >> v; u--; v--;
        G[3*u].push_back(3*v+1);
        G[3*u+1].push_back(3*v+2);
        G[3*u+2].push_back(3*v);
    }

    ll S, T; cin >> S >> T; S--; T--;
    queue<ll> que;
    vector<ll> d(3*N, INF);
    que.push(3*S);
    d[3*S] = 0;

    ll node;
    while(!que.empty()){
        node = que.front(); que.pop();
        for (ll next : G[node]){
            if(d[next] != INF) continue;
            d[next] = d[node] + 1;
            que.push(next);
        }
        if(d[3*T] != INF) break;
    }

    if(d[3*T] == INF){
        printf("-1\n");
    }
    else{
        printf("%lld\n", d[3*T]/3);
    }

}
