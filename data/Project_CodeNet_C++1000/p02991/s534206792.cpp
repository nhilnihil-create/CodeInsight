#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1000;

int main() {
    int n, m; cin >> n >> m;
    vvint g(3*n);
    rep(i,m) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[3*u].push_back(3*v+1);
        g[3*u+1].push_back(3*v+2);
        g[3*u+2].push_back(3*v);
    }
    int s, t; cin >> s >> t;
    s--; t--;
    vint dis(3*n,inf);
    queue<int> q;
    dis[3*s] = 0;
    q.push(3*s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int n_v : g[v]) {
            if (dis[n_v] != inf) continue;
            dis[n_v] = dis[v] + 1;
            q.push(n_v);
        }
    }
    if (dis[3*t] != inf) cout << dis[3*t]/3 << endl;
    else cout << -1 << endl;
}