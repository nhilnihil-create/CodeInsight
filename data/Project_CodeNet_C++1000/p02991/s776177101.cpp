#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

struct UnionFind{
    vector<int> par;
    int count;
    UnionFind(int n) : par(n, -1), count(0){}
    int Find(int x){return par[x] < 0 ? x : Find(par[x]);}
    int Size(int x){return par[x] < 0 ? -par[x] : Size(par[x]);}
    bool Unite(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y)
            return false;
        if(par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return ++count;
    }
};



signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].emplace_back(v);
    }
    int s, t;
    cin >> s >> t;
    --s, --t;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> que;
    vector<vector<int>> dist(n, vector<int>(3, MOD));
    dist[s][0] = 0;
    que.emplace(0, s, 0);
    while(!que.empty()){
        int x, d, mo;
        tie(d, x, mo) = que.top();
        que.pop();
        if(dist[x][mo] != d)
            continue;
        for(auto ed : edges[x]){
            if(chmin(dist[ed][(mo + 1) % 3], d + 1))
                que.emplace(dist[ed][(mo + 1) % 3], ed, (mo + 1) % 3);
        }
    }
    cout << (dist[t][0] == MOD ? -1 : dist[t][0] / 3) << endl;
}