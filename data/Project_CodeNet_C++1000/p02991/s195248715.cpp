#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

// ref : https://drken1215.hatenablog.com/entry/2019/07/01/111500

int seen[100010];
ll dist[100010][3];
vector<int> g[100010];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    rep(i, 100010) rep(j, 3) dist[i][j] = -1; 
    int s, t;
    cin >> s >> t;
    s--, t--;

    dist[s][0] = 0;
    queue<pair<int,int>> que;
    que.push({s, 0});

    while(!que.empty()){
        P now = que.front();
        que.pop();
        int v = now.first;
        int parity = now.second;
        for (auto nv : g[v]) {
            int np = (parity + 1) % 3;
            if (dist[nv][np] == -1) {
                dist[nv][np] = dist[v][parity] + 1;
                que.push({nv, np});
            }
        }
    }
    
    if(dist[t][0] != -1) cout << dist[t][0] / 3 << endl;
    else cout << -1 << endl;

    return 0;
}
