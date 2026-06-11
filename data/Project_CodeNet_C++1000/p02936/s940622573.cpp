#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007
 
using graph = vector<vector<ll>>;
int jikan;
bool seen[200010];
ll sum[200010];
ll ans[200010];
void dfs(const graph &G, int v, ll parent, ll val){
    //seen[v] = true;
    //root[v].push_back(v);
    sum[v] += val;
 
    for(auto next_v : G[v]){
        //ans[next_v] = v+1;
        //first[next_v] = jikan;
        //ans[next_v] += ans[v];
 
        if (next_v == parent) continue;
        dfs(G, next_v,v,sum[v]);
      //root[v].push_back(next_v);
      /*for(auto hoge : root[next_v]){
        root[v].push_back(hoge);
      }*/
    }
}
 
int main(){
    ll n,q;
    cin >> n >> q;
    graph g(n);
    graph root(n);
  ll ans[n];
    rep(i,n){
        seen[i] = false;
      ans[i] = 0;
    }
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,q){
        ll a,b;
        cin >> a >> b;
        sum[a-1] += b;
    }
    dfs(g,0,-1,0);
    rep(i,n){
        if(i < n-1) cout << sum[i] << ' ';
        else cout << sum[i] << endl;
    }
 
}