#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

std::vector<int> to[200005];
std::vector<int> ans;

void dfs(int v, int p=-1){
    for(int u : to[v]){
        if(u==p) continue;
        ans[u] += ans[v];
        dfs(u,v);
    }
}

int main(){
    int n,q; std::cin >> n >> q;

    rep(i,n-1){
        int a, b; std::cin >> a >> b; a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    ans.resize(n);
    rep(i,q){
        int p, x; std::cin >> p >> x; p--;
        ans[p] += x;
    }

    dfs(0);

    rep(i,n){
        std::cout << ans[i] << " ";
    }
    return 0;
}
