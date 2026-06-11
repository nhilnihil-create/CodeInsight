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

int main(){
    ll N, M;
    cin >> N >> M;
    VVL G(N+1);
    rep(i, 0, M){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    ll S, T;
    cin >> S >> T;
    VVL dist(N+1, VL(3, -1));
    dist[S][0] = 0;
    queue<PL> que;
    que.push({S, 0});
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        for(auto g : G[q.first]){
            ll ns = (q.second + 1) % 3;
            if(dist[g][ns] == -1){
                dist[g][ns] = dist[q.first][q.second] + 1;
                que.push({g, ns});
            }
        }
    }
    if(dist[T][0] == -1) cout << -1 << endl;
    else cout << dist[T][0]/3 << endl;
    return 0;
}