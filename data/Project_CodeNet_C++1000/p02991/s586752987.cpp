#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n);
    rep(i, m){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    ll s, t;
    cin >> s >> t;
    s--, t--;

    // ３の倍数という制約のため，u_0, u_1, u_2のように扱う（_以降があまり）．
    vector<vector<ll>> dist(n, vector<ll>(3, -1));
    dist[s][0] = 0;

    queue<pll> que;
    que.push(make_pair(s, 0));

    while(!que.empty()){
        pll crr = que.front();
        ll v = crr.first;
        ll p = crr.second;
        que.pop();

        ll next_p = (p+1) % 3;

        for(ll vi : g[v]){
            if(dist[vi][next_p] >= 0)continue;

            dist[vi][next_p] = dist[v][p] + 1;
            que.push(make_pair(vi, next_p));
        }
    }

    if(dist[t][0] < 0)cout << -1 << endl;
    else cout << dist[t][0] / 3 << endl;
}