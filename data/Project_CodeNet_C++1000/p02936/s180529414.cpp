#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> depth;
vector<int> score;
vector<int> p, x;

void search_depth(const Graph &G, int v, int parent, int dep){
    depth[v] = dep;

    for(auto next_v : G[v]){
        if(next_v == parent) continue;
        search_depth(G, next_v, v, dep + 1);
    }
}
void dfs(const Graph &G, int v, int parent){
    seen[v] = true;
    score[v] += score[parent];

    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v, v);
    }
}

int main(){
    int n, q; cin >> n >> q;

    Graph G(n);
    depth.resize(n);
    seen.resize(n);
    p.resize(q);
    x.resize(q);
    score.resize(n);
    rep(i, n) score[i] = 0;

    rep(i, n - 1){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, q){
        cin >> p[i] >> x[i];
        p[i]--;
    }
    depth.assign(n, 0);
    search_depth(G, 0, -1, 0);

    rep(i, q) score[p[i]] += x[i];
    dfs(G, 0, -1);

    rep(i, n){
        if(i == n - 1){
            cout << score[i] << endl;
            return 0;
        }
        cout << score[i] << " ";
    }
}