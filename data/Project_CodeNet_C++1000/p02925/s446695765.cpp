/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+5 ;

int n ,x ,day[N] ;
long long cur[N] ;
deque<int> dq[N] ;
int vis[N][N] ,vid ;
long long dfs(int i,int tar){
    if(vis[i][tar] == vid){
        cout << -1 ;
        exit(0);
    }
    vis[i][tar] = vid ;

    for(int k=day[i];k<dq[i].size();++k){
        int j = dq[i][k] ;
        if(j==tar) break;

        if(dq[j][day[j]] == i){
            ++day[i] ;
            ++day[j] ;
            int mx = max(cur[i],cur[j]);
            cur[i] = cur[j] = mx+1 ;
            continue ;
        }
        cur[i] = max(cur[i],dfs(j,i)) ;
        ++day[i] ;
        ++day[j] ;
        int mx = max(cur[i],cur[j]);
        cur[i] = cur[j] = mx+1 ;
    }
    return cur[i];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<n;++j){
            scanf("%d",&x);
            dq[i].push_back(x);
        }
    }
    long long ans = 0 ;
    for(int i=1;i<=n;++i){
        ++vid ;
        ans = max(ans ,dfs(i,i)) ;
    }
    cout << ans ;
    return 0;
}
