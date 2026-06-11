#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

/*
Arguments:
- G   : 隣接リスト {destination edge, cost}
- d   : srtからの距離 <- これを変更する
- srt : 始点
*/

void dijkstra(vector<vector<pair<ll,ll>>> G, vector<ll> &d, ll srt){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
    que.push({0, srt});
    d[srt] = 0;
    while(!que.empty()){
        auto q = que.top();
        que.pop();
        if(q.first > d[q.second]) continue;
        for(auto g : G[q.second]){
            if(d[g.first] <= q.first + g.second) continue;
            d[g.first] = q.first + g.second;
            que.push({d[g.first], g.first});
        }
    }
}

int main(){

    ll n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    VVP G(n);
    rep(i, 0, n-1){
        G[i].push_back({i+1, 1});
        G[i+1].push_back({i, 1});
    } 
    G[x].push_back({y, 1});
    G[y].push_back({x, 1});
    VL d(n), ans(n, 0);
    rep(i, 0, n) {
        rep(j, 0, n) d[j] = 1e18;
        dijkstra(G, d, i);
        rep(j, i+1, n) ans[d[j]]++;
    }
    rep(i, 1, n) cout << ans[i] << endl;
    return 0;
}