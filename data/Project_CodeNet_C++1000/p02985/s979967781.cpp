#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

//editorialのサンプルコードをお手本に再帰関数dfsで

ll dfs(vv &graph, int i, int m, int k){
    //大祖先: 自身がK通り.
    //子の数をcとしてK-1 P c通り
    //それ以外: 自身は既に数えられている(1通り).
    //子の数をcとしてK-2 P c通り
    ll rtn;
    int num = k-1;
    if(m==-1){
        rtn = k;
    }else{
        rtn = 1;
        num--;
    }
    
    for(auto d : graph[i]){
        if(d==m)continue;
        rtn *= num;
        rtn %= MOD;
        num--;
        rtn *= dfs(graph, d, i, k);
        rtn %= MOD;
    }
    return rtn;
}

int main(){
    int n,k;
    cin >> n >> k;
    
    vv graph(n);
    
    int a,b;
    rep(i,n-1){
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    ll ans = dfs(graph, 0, -1, k);
    cout << ans << endl;
    return 0;
}