/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ,mod = 1e9+7 ;

int n ,k ,u ,v ,ans = 1 ;
vector<int> adj[N] ;
void dfs(int p,int gp,int take){
    if(take>=k){
        cout << 0;
        exit(0);
    }
    int c = k - take ;

    ans = 1ll*ans*c%mod ;
    int cur = 1+(gp!=0) ;
    for(int ch:adj[p]){
        if(ch==gp) continue ;
        dfs(ch,p,cur++);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    if(n==1) return cout << k,0 ;
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0) ;
    cout << ans ;
    return 0;
}
