#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

const int MAX_V = 1e5;
vector<int> es[3*MAX_V];
vector<int> d(3*MAX_V, inf);

void add_edge(int u, int v){
    rep(i, 3){
        int j = (i+1)%3;
        es[i*MAX_V+u].pb(j*MAX_V+v);
    }
}

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii> > que;
    d[s] = 0;
    que.push(pii(0, s));
    while(!que.empty()){
        pii p = que.top();
        que.pop();
        int i = p.second;
        if(d[i] < p.first) continue;
        for(auto &e: es[i]){
            if(d[e] > d[i]+1){
                d[e] = d[i]+1;
                que.push(pii(d[e], e));
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        add_edge(u, v);
    }
    int S, T; cin >> S >> T; S--, T--;
    dijkstra(S);
    if(d[T] == inf) cout << -1 << endl;
    else cout << d[T]/3 << endl;
}