#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
vector<vector<int>> d(200005);
vector<int> value(200005);

void dfs(int x,int p){
    for(auto np:d[x]){
        if(np==p)continue;
        value[np]+=value[x];
        dfs(np,x);
    }
}

int main(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        int p,x;cin>>p>>x;
        p--;
        value[p]+=x;
    }
    dfs(0,-1);
    for(int i=0;i<n;i++)cout<<value[i]<<endl;
}