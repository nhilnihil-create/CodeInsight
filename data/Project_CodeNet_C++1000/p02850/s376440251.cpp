#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

struct Edge {
    int id, to;
};
using ve  = vector<Edge>;
using vve = vector<ve>;

int num_color = 0;
vve edges;
vl ans;

void dfs(int v, int pre_color=-1, int parent=-1) {
    int now_color = 0;
    for (auto e : edges[v]) {
        if (e.to == parent) continue;
        if (now_color == pre_color) now_color++;
        ans[e.id] = now_color;
        dfs(e.to, now_color, v);
        now_color++;
    }
}

int main() {
    int N;
    cin >> N;
    edges.resize(N);
    ans.resize(N-1);
    rep(i,N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        Edge e1{i, b};
        Edge e2{i, a};
        edges[a].push_back(e1);
        edges[b].push_back(e2);
    }
    rep(i,N) num_color = max(num_color, (int)edges[i].size());
    dfs(0);
    cout << num_color << endl;
    rep(i,N-1) {
        cout << ans[i]+1 << endl;
    }
    return 0;
}
