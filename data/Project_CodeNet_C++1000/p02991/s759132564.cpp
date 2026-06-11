//ABC132E
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
typedef vector<ll> V;
const ll INF = 1145141919;

V g[101010];
ll cost[101010][3];

int main(){
    
    ll N, M, S, T;
    cin >> N >> M;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    cin >> S >> T;
    
    rep(i, 101010)rep(j, 3)cost[i][j] = INF;
    cost[S][0] = 0;
    queue<P>Q;
    Q.push(P(S, 0));
    while(!Q.empty()){
        ll pos = Q.front().first;
        ll step = Q.front().second;
        Q.pop();
        if(pos == T && step == 0){
            cout << cost[pos][step] / 3 << endl;
            return 0;
        }
        for(auto to : g[pos]){
            ll next_step = (step + 1) % 3;
            if(cost[to][next_step] < INF)continue;
            cost[to][next_step] = cost[pos][step] + 1;
            Q.push(P(to, next_step));
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}