#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p = -1){
    for(int u : to[v]) if(u != p) {
            ans[u] += ans[v];
            dfs(u, v);
        }
}


int main() {
    int n, q; cin >> n >> q;
    rep(i, n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n);
    rep(i,q){
        int p, x;
        cin >> p >> x;
        p--;
        ans[p]+=x;
    }
    dfs(0);
    rep(i, n){
        cout << ans[i] <<( i < n-1 ? ' ' : '\n') ;
    }
    return 0;
}
