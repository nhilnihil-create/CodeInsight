#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 1000010;

typedef struct UnionFindTree{
    vector<int> par;

    UnionFindTree(int n): par(n, -1){}

    int find(int x){
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    int size(int x){
        return -par[find(x)];
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(size(x) < size(y)) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
}UF;

template<class T> struct edge{
    int from, to; T cost;
    edge(int f, int t, T c): from(f), to(t), cost(c){}
};

template<class T> struct Graph{
    vector<vector<edge<T>>> G;
    int n;

    Graph(int n_): n(n_){
        G.resize(n);
    }

    void add_edge(int f, int t, T c){
        G[f].emplace_back(f, t, c);
    }

    pair<bool, vector<T>> bellman_ford(int s){
        T d_INF = numeric_limits<T>::max();
        vector<T> d(n, d_INF);
        vector<edge<T>> E;
        rep(i, n)for(edge<T> &e: G[i]) E.push_back(e);
        d[s] = 0;
        rep(i, n)for(edge<T> &e: E){
            if(d[e.from] != d_INF && d[e.from] + e.cost < d[e.to]){
                d[e.to] = d[e.from] + e.cost;
                if(i == n-1) return make_pair(true, d);
            }
        }
        return make_pair(false, d);
    }

    vector<T> dijkstra(int s){
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        vector<T> d(n, numeric_limits<T>::max());
        d[s] = 0;
        que.push(P((T)0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(edge<T> &e : G[v]){
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
        return d;
    }

    pair<bool, vector<vector<T>>> warshall_floyd(){
        T d_INF = numeric_limits<T>::max();
        vector<vector<T>> d = vector<vector<T>>(n, vector<T>(n, d_INF));
        rep(i, n){
            for(edge<T> &e: G[i]) d[i][e.to] = e.cost;
            d[i][i] = 0;
        }
        rep(k, n)rep(i, n)rep(j, n)if(d[i][k] < d_INF && d[k][j] < d_INF){
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        rep(i, n)if(d[i][i] < 0) return make_pair(true, d);
        return make_pair(false, d);
    }

    pair<T, Graph<T>> kruskal(){
        vector<edge<T>> E;
        rep(i, n)for(edge<T> &e: G[i]) E.push_back(e);
        sort(E.begin(), E.end(), [](const edge<T> &e1, const edge<T> &e2){return e1.cost < e2.cost;});
        UF uf(n);
        T ret = 0;
        Graph<T> MST(n);
        for(edge<T> &e: E){
            if(!uf.same(e.from, e.to)){
                uf.unite(e.from, e.to);
                ret += e.cost;
                MST.add_edge(e.from, e.to, e.cost);
                MST.add_edge(e.to, e.from, e.cost);
            }
        }
        return {ret, MST};
    }

    pair<bool, vector<int>> toposo(){
        vector<int> ret(n, -1), in(n, 0);
        rep(i, n)for(edge<T> &e: G[i]) ++in[e.to];
        int cur = 0;
        stack<int> st;
        rep(i, n)if(!in[i]) st.push(i);
        if(st.empty()) return make_pair(false, ret);
        while(!st.empty()){
            int v = st.top(); st.pop();
            ret[cur++] = v;
            for(edge<T> &e: G[v]){
                if(!in[e.to]) return make_pair(false, ret);
                --in[e.to];
                if(!in[e.to]) st.push(e.to);
            }
        }
        return make_pair(cur==n, ret);
    }

    bool has_cycle(){
        return !toposo().fi;
    }

    void scc_dfs(int v, vector<bool> &used, vector<int> &vs){
        used[v] = true;
        for(edge<T> &e: G[v])if(!used[e.to]) scc_dfs(e.to, used, vs);
        vs.push_back(v);
    }

    void scc_rdfs(int v, int k, vector<int> &cmp, vector<bool> &used, vector<vector<int>> &rG){
        used[v] = true;
        cmp[v] = k;
        for(int nv: rG[v])if(!used[nv]) scc_rdfs(nv, k, cmp, used, rG);
    }

    tuple<int, vector<int>, vector<vector<int>>> scc(){
            vector<vector<int>> rG(n);
            rep(i, n)for(edge<T> &e: G[i]) rG[e.to].push_back(i);
            vector<bool> used(n, false);
            vector<int> vs;
            vector<int> vtoc(n);
            rep(i, n)if(!used[i]) scc_dfs(i, used, vs);
            fill(used.begin(), used.end(), false);
            int k = 0;
            vector<vector<int>> ctov=vector<vector<int>>(n, vector<int>());
            rrep(i, n)if(!used[vs[i]]) scc_rdfs(vs[i], k++, vtoc, used, rG, ctov);
            return make_tuple(k, vtoc, ctov);
    }

    int bridge_dfs(int v, int pv, int &idx, vector<int> &ord, vector<int> &low, vector<pii> &bridge){
        ord[v]=low[v]=idx++;
        for(auto &e: G[v])if(e.to!=pv){
            int nv=e.to;
            if(ord[nv]<0){
                chmin(low[v], bridge_dfs(nv, v, idx, ord, low, bridge));
                if(low[nv]>ord[v]) bridge.emplace_back(min(v, nv), max(v, nv));
            }
            else chmin(low[v], ord[nv]);
        }
        return low[v];
    }

    vector<pii> get_bridge(){
        vector<int> ord(n, -1), low(n, -1);
        vector<pii> bridge;
        int idx=0;
        bridge_dfs(0, -1, idx, ord, low, bridge);
        sort(bridge.begin(), bridge.end());
        bridge.erase(unique(bridge.begin(), bridge.end()), bridge.end());
        return bridge;
    }

    int art_dfs(int v, int prev, int &idx, vector<int> &ord, vector<int> &low, vector<int> &art){
        ord[v]=low[v]=idx++;
        for(auto &e: G[v])if(e.to!=prev){
            int nv=e.to;
            if(ord[nv]<0){
                chmin(low[v], art_dfs(nv, v, idx, ord, low, art));
                if((prev<0 && ord[nv]!=1) || (prev>=0 && low[nv]>=ord[v])){
                    art.push_back(v);
                }
            }
            else chmin(low[v], ord[nv]);
        }
        return low[v];
    }

    vector<int> get_art(){
        vector<int> ord(n, -1), low(n, -1), art;
        int idx=0;
        art_dfs(0, -1, idx, ord, low, art);
        sort(art.begin(), art.end());
        art.erase(unique(art.begin(), art.end()), art.end());
        return art;
    }
};

int id[1010][1010], a[1010][1010], d[MAX];

int dfs(int v, Graph<int> &gr){
    if(d[v] >= 0) return d[v];
    d[v] = 0;
    for(auto &e: gr.G[v]){
        chmax(d[v], dfs(e.to, gr) + 1);
    }
    return d[v];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0, cur=0; i<n; ++i)For(j, i+1, n){
        id[i][j] = id[j][i] = cur++;
    }
    Graph<int> gr(n*(n-1)/2);

    rep(i, n){
        rep(j, n-1){
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
        rep(j, n-2) gr.add_edge(id[i][a[i][j]], id[i][a[i][j+1]], 1);
    }
    if(gr.has_cycle()){
        puts("-1");
        return 0;
    }

    fill(d, d+n*(n-1)/2, -1);
    int ans = 0;
    rep(i, n)For(j, i+1, n){
        chmax(ans, dfs(id[i][j], gr));
    }
    printf("%d\n", ans+1);
}