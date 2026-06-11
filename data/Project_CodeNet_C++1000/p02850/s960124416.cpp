#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

using Edge = pair<long long, long long>;
using Graph = vector<vector<Edge> >;

long long n;
Graph G;

vector<long long> res(100000, -1);

void dfs(long long v, long long p, long long pc){
    long long color = 1;
    if(pc == color) color++;
    
    for(auto next : G[v]){
        if(next.first == p) continue;
        res[next.second] = color;
        dfs(next.first, v, color);
        color++;
        if(pc == color) color++;
    }
}

int main(){
    cin >> n;

    G.assign(n, vector<Edge>());

    for(long long i = 0; i < n-1; i++){
        long long a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }

    long long maxv = 0;

    for(long long i = 0; i < n; i++) maxv = max(maxv, (long long)G[i].size());
    
    dfs(0, -1, -1);

    cout << maxv << endl;

    for(long long i = 0; i < n-1; i++) cout << res[i] << endl;
    
    return 0;
}