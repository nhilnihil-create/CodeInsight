#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using graph = vector<vector<ll>>;
const ll nmax = 100001;

ll n, m; 

ll notop[nmax];
ll h[nmax];

bool dfs(ll v, const graph &G){
    
    for(auto nv : G[v]){
        
      	
        if(h[v]<=h[nv]){
          
          notop[v]++; return false;
        }
        
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(ll i=0; i<n; ++i){cin >> h[i];}

    graph g(n);
    for(ll i=0; i<m; ++i){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    
    memset(notop, 0, sizeof(notop));
    ll res = 0; 
    for(ll i=0; i<n; ++i){
        
        if(notop[i]!=0){continue;}
        if(dfs(i, g)){
            res++; 
        } 
    }
    cout << res << endl;
    return 0;
}