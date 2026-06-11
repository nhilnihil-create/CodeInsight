#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

vector<bool> seen;
vector<int> values;
vector<int> ans;

void dfs(Graph &G, int v, int val){
    seen[v] = true;
    int tmp = val + values[v];
    ans[v] = tmp;
    for(auto next_v: G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v, tmp);
    }
}

int main(){
    int N, Q; cin >> N >> Q;
    Graph g(N);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    values.assign(N, 0);
    ans.assign(N, 0);
    rep(i, Q){
        int p, x; cin >> p >> x;
        p--;
        values[p] += x;
    }
    seen.assign(N, false);
    dfs(g, 0, 0);

    rep(i, N) cout << ans[i] << endl;
}