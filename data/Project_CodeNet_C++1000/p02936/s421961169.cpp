#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double; 
int INF = 1e9;

vector<int> cnt(200005);
vector<bool> seen(200005);
void dfs(const vector<vector<int>> &G,int v){
  for(int nv : G[v]){
    if(seen[nv]) continue;
    seen[nv] = true;
    cnt[nv] += cnt[v];
    dfs(G,nv);
  }
  return;
}
int main(){
  int n,q;cin >> n >> q;
  vector<vector<int>> G(200005);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,q){
    int p,x;cin >> p >> x;
    --p;
    cnt[p] += x;
  }
  rep(i,n) seen[i] = false;
  seen[0] = true;
  dfs(G,0);
  rep(i,n) cout << cnt[i] << " ";

}