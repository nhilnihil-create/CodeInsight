#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+1;
const int M = 1e9+7;
vector<vector<int>> g(N);

ll dfs(int x, int p, int k){
    int num;
    if(p == -1) num = k-1;
    else num = k-2;

    if((int)g[x].size()>k) return 0;
    else {
        ll res = 1;
        for(auto to:g[x]){
            if(to==p)  continue;
            res*=num%M;
            res%=M;
            num--;
        }
    

    for(auto to: g[x]){
        if( to==p) continue;
        res *= dfs(to,x,k);
        res%=M;
    }
    return res;
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = k*dfs(0,-1,k);
    cout<<ans%M;
}
