#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 3e5 + 5;
vector<ll> node[N];
ll vis[N], d[N];
void bfs(ll u){
        queue<ll> q;
        q.push(u);
        d[u] = 0;
        vis[u] = 1;
        while (q.size() > 0) {
                ll now = q.front();
                q.pop();
                for (auto j : node[now]){
                        if (vis[j] == 0){
                                vis[j] = 1;
                                d[j] = d[now] + 1;
                                q.push(j);
                        }
                }
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("WALKING.INP", "r")){
                freopen("WALKING.INP", "r", stdin);
                freopen("WALKING.OUT", "w", stdout);
        }
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v + n);
                node[u + n].push_back(v + n * 2);
                node[u + 2 * n].push_back(v);
        }
        ll s, t;
        cin >> s >> t;
        bfs(s);
        if (d[t] == 0) cout << -1;
        else cout << d[t] / 3;
}
