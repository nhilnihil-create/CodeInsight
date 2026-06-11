#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> ans;
vector<vector<int>> g(200005,vector<int> (0));
void dfs(int v,int p){
    for(auto i:g[v]){
        if(i==p) continue;
        ans[i] += ans[v];
        dfs(i,v);
    }
}
int main(){
    int n,q;
    cin >> n >> q;
    ans.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,q){
        int p1,x1;
        cin >> p1 >> x1;
        p1--;
        ans[p1] += x1;
    }
    dfs(0,-1);
    rep(i,n) cout << ans[i] << ' ';
    cout << endl;
}