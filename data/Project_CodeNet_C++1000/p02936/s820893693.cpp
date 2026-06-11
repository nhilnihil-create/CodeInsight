#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

using Graph = vector<vector<long long> >;
Graph G;

long long n, q;
vector<long long> cnt(200001, 0);
vector<long long> ans(200001 ,0);

void dfs(long long v, long long p){
    if(p != -1) ans[v] += ans[p];
    ans[v] += cnt[v];

    for(auto next : G[v]){
        if(next == p) continue;
        dfs(next, v);
    }
}


int main(){
    cin >> n >> q;
    G.assign(n, vector<long long>());

    for(long long i = 0; i < n-1; i++){
        long long a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(long long i = 0; i < q; i++){
        long long p, x;
        cin >> p >> x;
        cnt[p-1] += x;
    }

    dfs(0, -1);

    for(long long i = 0; i < n; i++){
        if(i != n-1) printf("%lld ", ans[i]);
        else printf("%lld\n", ans[i]);
    }
    return 0;
}