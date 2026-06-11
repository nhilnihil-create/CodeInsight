#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
vector<int> g[N];
int n , m , vis[N] ,ans , c;

void dfs(int x){
    if(vis[x]) return;
    vis[x] = 1;
    c++; 
    for(auto i : g[x]) dfs(i);
}

int32_t main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; ++i){
        int a , b ; cin >> a >> b ;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(vis[i]) continue;
        dfs(i);
        ans = max(ans,c);
        c = 0;
    }
    cout << ans << endl;
    return 0;
}