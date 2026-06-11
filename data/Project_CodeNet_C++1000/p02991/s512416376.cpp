#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(3*n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(n+v);
        G[n+u].push_back(2*n+v);
        G[2*n+u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;

    vector<int> res(3*n, INF);
    queue<int> que;
    res[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (res[nv] == INF) {
                res[nv] = res[v] + 1;
                que.push(nv);
            }
        }
    }

    cout << (res[t] == INF ? -1 : res[t]/3) << endl;
}