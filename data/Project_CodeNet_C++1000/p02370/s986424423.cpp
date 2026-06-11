#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
vector<int>to[10010],ans;
bool ok[10010];

void dfs(int v){
    ok[v]=true;
    for(int u:to[v]){
        if(ok[u])continue;
        dfs(u);
    }
    ans.push_back(v);
    return;
}

void Tsort(){
    rep(i,n){
        if(!ok[i])dfs(i);
    }
    return;
}

int main(){
    cin>>n>>m;
    rep(i,m){
        int s,t; cin>>s>>t;
        to[s].push_back(t);
    }
    Tsort();
    reverse(ans.begin(),ans.end());
    for(auto& x:ans){
        cout<<x<<endl;
    }
    return 0;
}
