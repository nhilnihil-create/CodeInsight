#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

vector<vector<int>> G;
vector<ll> ans;

void dfs(int cu,int pa=-1){
    for(auto to : G[cu]){
        if(pa==to) continue; // 逆流防止
        ans[to]+=ans[cu];
        dfs(to,cu);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    
    G.resize(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);      
    }

    ans.resize(n);
    rep(i,q){
        int p,x;
        cin>>p>>x;
        p--;
        ans[p]+=x;
    }

    dfs(0);
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}