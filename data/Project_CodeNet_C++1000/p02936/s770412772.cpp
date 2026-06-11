#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> connect(200005);
vector<int> val;

void dfs(int i,int k=-1){
    for(auto p:connect[i]){
        if(p==k) continue;
        val[p]+=val[i];
        dfs(p,i);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        --a;--b;
        connect[a].push_back(b);connect[b].push_back(a);
    }
    val.resize(n);
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        --a;
        val[a]+=b;
    }
    dfs(0);
    rep(i,n)cout<<val[i]<<endl;
    return 0;
}