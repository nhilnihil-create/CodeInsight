#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;
const ll INF = 1e16;

typedef pair<ll, ll> P;

vector<ll> G[3 * 100100];
ll N, M;
ll d[3*100100];

void dijkstra(ll s){
    REP(i,3*N) d[i] = INF;
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(d[s], s));
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        ll v = p.second;
        ll dist = p.first;
        if(d[v] < dist) continue;
        for(auto&& n : G[v]){
            ll dist2 = dist + 1;
            if(dist2 < d[n]){
                d[n] = dist2;
                que.push(P(dist2, n));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    REP(i,M){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        REP(k,3){
            G[N*k + u].push_back(N*((k+1)%3) + v);
        }
    }
    ll S, T;
    cin >> S >> T;
    S--, T--;

    dijkstra(S);
    //ll ans = d[2*N+T];
    ll ans = d[T];
    if(ans == INF)
        cout << -1 << endl;
    else
        cout << ans/3 << endl;
    return 0;
}
