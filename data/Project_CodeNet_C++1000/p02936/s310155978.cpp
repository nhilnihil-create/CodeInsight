#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);i++)

vector<int> num;
vector<vector<int>> e;

void dfs(int v,int now,int x){
    num[v] += x;
    for(auto p:e[v]){
        if(p == now)continue;
        dfs(p,v,num[v]);
    }
}

int main(void){
    int n,q;cin >> n >> q;
    int a[n],b[n],p[q],x[q];
    num.resize(n);
    e.resize(n);
    
    rep(i,n-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    rep(i,q){
        cin >> p[i] >> x[i];
        p[i]--;
        num[p[i]] += x[i];
    }
    
    dfs(0,-1,0);
    
    rep(i,n)cout << num[i] << " "; 
}