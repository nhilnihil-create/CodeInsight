// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
vector<vector<int>> g;
vector<int> height;
ll ans = 0;
void dfs(ll idx){
    for(int i : g[idx]){
        if(height[i] >= height[idx])
            return ;
    }
    ++ans;
}
void solve(){
    ll n, m;
    cin>>n>>m;
    g.resize(n+1);
    height.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin>>height[i];
    for(int i = 0; i < m; i++){
        int f, s;
        cin>>f>>s;
        g[f].push_back(s);
        g[s].push_back(f);
    }
    for(int i = 1; i <= n; i++){
        // vector<int> vis(n+1, 0);
        dfs(i);
    }
    cout<<ans;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}