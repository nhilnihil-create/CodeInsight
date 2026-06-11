#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

vector<vector<int>> to(200005);
vector<ll> ans;

void dfs(int v,int p = -1){
    for(int u : to.at(v)){
        if(u == p)continue;
        ans.at(u) += ans.at(v);
        dfs(u,v);
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    // vector<vector<int>> AB(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to.at(a).push_back(b);
        to.at(b).push_back(a);
    }
    // vector<ll> PX(n,0);
    ans.resize(n);
    rep(i,q){
        int p,x;
        cin >> p >> x;
        p--;
        ans.at(p) += x;
    }
    dfs(0);
    rep(i,n){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}