#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

vector<int> res;

void dfs(vector<vector<pii>> &G, int v, int p, int pc){
    int color = 0;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (color == pc) color++;
        res[e.second] = color;
        dfs(G, e.first, v, color);
        color++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<pii>> G(n);
    res.assign(n-1, -1);
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(pii(b, i));
        G[b].push_back(pii(a, i));
    }

    int deg = 0;
    for (int i = 0; i < n; ++i) {
        chmax(deg, (int)G[i].size());
    }
    dfs(G, 0, -1, -1);

    cout << deg << endl;
    for (int i = 0; i < n-1; ++i) {
        cout << res[i]+1 << endl;
    }
}